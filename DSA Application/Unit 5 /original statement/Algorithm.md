Start the program.

Read the number of power substations and power lines.

Assign a unique number to each substation.

Store the power lines as weighted edges in an adjacency list and edge list.

Select a starting substation.

Apply BFS to visit all reachable substations.

If all substations are visited, the graph is connected; otherwise, it is disconnected.

Sort all edges in ascending order of their weights.

Apply Kruskal’s algorithm using a Disjoint Set Union (DSU) structure to select edges without forming cycles.

Calculate the total MST cost if the graph is connected.

Display the reachable substations, selected MST edges and total cost.

Stop.
