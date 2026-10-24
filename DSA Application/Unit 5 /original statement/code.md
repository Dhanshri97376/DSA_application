#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

class PowerNetwork
{
    int n, m;
    vector<Edge> edges;
    vector<vector<int> > adj;

    int findParent(vector<int>& parent, int x)
    {
        if (parent[x] == x)
            return x;

        parent[x] = findParent(parent, parent[x]);
        return parent[x];
    }

    bool unite(vector<int>& parent, vector<int>& rankSet,
               int u, int v)
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

public:
    PowerNetwork()
    {
        n = 0;
        m = 0;
    }

    bool createNetwork()
    {
        cout << "Enter number of substations: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Invalid number of substations.\n";
            return false;
        }

        cout << "Enter number of power lines: ";
        cin >> m;

        if (m < 0)
        {
            cout << "Invalid number of power lines.\n";
            return false;
        }

        adj.resize(n);

        cout << "\nEnter power lines as: "
             << "substation1 substation2 cost\n";

        for (int i = 0; i < m; i++)
        {
            Edge e;

            cout << "Edge " << i + 1 << ": ";
            cin >> e.u >> e.v >> e.weight;

            if (e.u < 0 || e.u >= n ||
                e.v < 0 || e.v >= n ||
                e.u == e.v || e.weight < 0)
            {
                cout << "Invalid edge. Try again.\n";
                i--;
                continue;
            }

            edges.push_back(e);
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }

        return true;
    }

    bool BFS(int start)
    {
        if (start < 0 || start >= n)
        {
            cout << "Invalid starting substation.\n";
            return false;
        }

        vector<bool> visited(n, false);
        queue<int> q;
        int count = 0;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS traversal: ";

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            count++;

            for (int i = 0; i < (int)adj[u].size(); i++)
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
        {
            cout << "Power network is connected.\n";
            return true;
        }

        cout << "Power network is disconnected.\n";
        return false;
    }

    void kruskal()
    {
        sort(edges.begin(), edges.end(), compareEdges);

        vector<int> parent(n);
        vector<int> rankSet(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int totalCost = 0;
        int selected = 0;

        cout << "\nEdges selected by Kruskal:\n";

        for (int i = 0;
             i < (int)edges.size() && selected < n - 1;
             i++)
        {
            Edge e = edges[i];

            if (unite(parent, rankSet, e.u, e.v))
            {
                cout << e.u << " -- " << e.v
                     << " : " << e.weight << endl;

                totalCost += e.weight;
                selected++;
            }
        }

        if (selected == n - 1)
            cout << "Minimum Spanning Tree cost = "
                 << totalCost << endl;
        else
            cout << "MST does not exist because "
                 << "the graph is disconnected.\n";
    }
};

int main()
{
    PowerNetwork p;
    int start;

    if (!p.createNetwork())
        return 0;

    cout << "\nEnter starting substation (0 to n-1): ";
    cin >> start;

    cout << "\n--- BFS Reachability ---\n";

    bool connected = p.BFS(start);

    if (connected)
    {
        cout << "\n--- Kruskal's Algorithm ---\n";
        p.kruskal();
    }
    else
    {
        cout << "\nMST cost is not calculated because "
             << "the network is disconnected or the "
             << "starting substation is invalid.\n";
    }

    return 0;
}
