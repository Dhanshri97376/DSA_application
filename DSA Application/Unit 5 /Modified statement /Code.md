
#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

bool compareEdges(Edge a, Edge b)
{
    return a.w < b.w;
}

class PowerNetwork
{
    int n;
    vector<Edge> edges;
    vector<vector<int> > adj;

public:
    PowerNetwork(int vertices)
    {
        n = vertices;
        adj.resize(n);
    }

    int vertexCount()
    {
        return n;
    }

    void addVertex()
    {
        n++;
        adj.resize(n);
        cout << "New substation added: "
             << n - 1 << endl;
    }

    void addEdge(int u, int v, int w)
    {
        if (u < 0 || v < 0 || u >= n ||
            v >= n || u == v || w < 0)
        {
            cout << "Invalid power line!" << endl;
            return;
        }

        Edge e;
        e.u = u;
        e.v = v;
        e.w = w;

        edges.push_back(e);
        adj[u].push_back(v);
        adj[v].push_back(u);

        cout << "Power line added successfully."
             << endl;
    }

    void displayGraph()
    {
        int i, j;

        cout << "\nAdjacency List:" << endl;

        for (i = 0; i < n; i++)
        {
            cout << "Substation " << i << ": ";

            for (j = 0; j < (int)adj[i].size(); j++)
                cout << adj[i][j] << " ";

            cout << endl;
        }

        cout << "\nPower Lines (u-v : cost):"
             << endl;

        for (i = 0; i < (int)edges.size(); i++)
        {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;
        }
    }

    int BFS(int start)
    {
        if (start < 0 || start >= n)
        {
            cout << "Invalid starting substation."
                 << endl;
            return -1;
        }

        vector<bool> visited(n, false);
        queue<int> q;
        int count = 0;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal: ";

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            count++;

            for (int i = 0;
                 i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i];

                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << "\nReachable substations: "
             << count << " out of " << n << endl;

        if (count == n)
            cout << "Network is connected." << endl;
        else
            cout << "Network is disconnected."
                 << endl;

        return count;
    }

    int findParent(vector<int>& parent, int x)
    {
        if (parent[x] == x)
            return x;

        parent[x] = findParent(parent, parent[x]);
        return parent[x];
    }

    bool unite(vector<int>& parent,
               vector<int>& rankSet, int u, int v)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u == v)
            return false;

        if (rankSet[u] < rankSet[v])
            parent[u] = v;
        else if (rankSet[u] > rankSet[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rankSet[u]++;
        }

        return true;
    }

    int kruskal()
    {
        vector<Edge> sorted = edges;

        sort(sorted.begin(), sorted.end(),
             compareEdges);

        vector<int> parent(n);
        vector<int> rankSet(n, 0);

        int i, cost = 0, selected = 0;

        for (i = 0; i < n; i++)
            parent[i] = i;

        cout << "\nMST Edges:" << endl;

        for (i = 0;
             i < (int)sorted.size() && selected < n - 1;
             i++)
        {
            Edge e = sorted[i];

            if (unite(parent, rankSet, e.u, e.v))
            {
                cout << e.u << " - " << e.v
                     << " : Cost = " << e.w << endl;

                cost += e.w;
                selected++;
            }
        }

        if (selected != n - 1)
        {
            cout << "MST unavailable: graph is "
                 << "disconnected." << endl;
            return -1;
        }

        cout << "Minimum MST cost = "
             << cost << endl;

        return cost;
    }
};

int main()
{
    int n, m, i;

    cout << "Enter number of substations: ";
    cin >> n;

    if (cin.fail() || n < 1)
    {
        cout << "Invalid number of substations."
             << endl;
        return 0;
    }

    PowerNetwork p(n);

    cout << "Enter number of power lines: ";
    cin >> m;

    if (cin.fail() || m < 0)
    {
        cout << "Invalid number of power lines."
             << endl;
        return 0;
    }

    cout << "\nEnter power lines (u v cost):"
         << endl;

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> w;

        if (cin.fail())
        {
            cout << "Invalid input." << endl;
            return 0;
        }

        p.addEdge(u, v, w);
    }

    cout << "\n===== ORIGINAL NETWORK =====" << endl;
    p.displayGraph();

    int start;

    cout << "\nEnter starting substation (0 to "
         << n - 1 << "): ";
    cin >> start;

    if (cin.fail() || start < 0 || start >= n)
    {
        cout << "Invalid starting substation."
             << endl;
        return 0;
    }

    cout << "\n===== ORIGINAL BFS =====" << endl;
    int oldReach = p.BFS(start);
    int oldCost = -1;

    if (oldReach == p.vertexCount())
    {
        cout << "\n===== ORIGINAL MST =====" << endl;
        oldCost = p.kruskal();
    }
    else
    {
        cout << "Original MST is unavailable."
             << endl;
    }

    int choice = 0;

    do
    {
        cout << "\n===== UPDATE MENU =====";
        cout << "\n1. Add new substation";
        cout << "\n2. Add new power line";
        cout << "\n3. Display current graph";
        cout << "\n4. Finish updates";
        cout << "\nEnter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid input." << endl;
            return 0;
        }

        if (choice == 1)
        {
            p.addVertex();
        }
        else if (choice == 2)
        {
            int u, v, w;

            cout << "Enter u v cost: ";
            cin >> u >> v >> w;

            if (cin.fail())
            {
                cout << "Invalid input." << endl;
                return 0;
            }

            p.addEdge(u, v, w);
        }
        else if (choice == 3)
        {
            p.displayGraph();
        }
        else if (choice != 4)
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    cout << "\n===== UPDATED NETWORK =====" << endl;
    p.displayGraph();

    cout << "\n===== UPDATED BFS =====" << endl;
    int newReach = p.BFS(start);
    int newCost = -1;

    if (newReach == p.vertexCount())
    {
        cout << "\n===== UPDATED MST =====" << endl;
        newCost = p.kruskal();
    }
    else
    {
        cout << "Updated MST is unavailable."
             << endl;
    }

    cout << "\n===== BEFORE AND AFTER COMPARISON ====="
         << endl;

    cout << "Original reachable substations: "
         << oldReach << endl;

    cout << "Updated reachable substations: "
         << newReach << endl;

    if (oldCost == -1)
        cout << "Original MST cost: Unavailable"
             << endl;
    else
        cout << "Original MST cost: "
             << oldCost << endl;

    if (newCost == -1)
        cout << "Updated MST cost: Unavailable"
             << endl;
    else
        cout << "Updated MST cost: "
             << newCost << endl;

    return 0;
}

