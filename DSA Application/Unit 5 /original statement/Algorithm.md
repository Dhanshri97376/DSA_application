1.Start the program.

2.Read the number of power substations and power lines.

3.Assign a unique number to each substation.

4.Store the power lines as weighted edges in an adjacency list and edge list.

5.Select a starting substation.

6.Apply BFS to visit all reachable substations.

7.If all substations are visited, the graph is connected; otherwise, it is disconnected.

8.Sort all edges in ascending order of their weights.

9.Apply Kruskal’s algorithm using a Disjoint Set Union (DSU) structure to select edges without forming cycles.

10.Calculate the total MST cost if the graph is connected.

11.Display the reachable substations, selected MST edges and total cost.

12.Stop.
