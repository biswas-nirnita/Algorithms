// MST: A connected subgraph which constains all the vertices w/o any cycle
// Prim's and Kruskal's algo is used to find MST for undirected graphs
#include <iostream>
#include <vector>
#include <DSU.cpp>
using namespace std;

/*
* Sort the edges in increasing order (ElogE), for each edge - if its not making cycle add that edge with the MST (E*alpha)
* if DFS is used in cycle detction alpha = O(V+E) , if union find is used alpha = O(1)
* If its already sorted then only T.C. of 2nd part

* Kruskal can handle -ve weights, adding const to weights doesn't change set of MSTs, only changes the weights, also change the shortest paths
*/
bool comparator(vector<int>& a , vector<int>& b)
{
    return a[2] < b[2];
}

// edges: {{source , destination , weight} , {} , {} , ... }
int kruskalAlgo(int V, vector<vector<int>>& edges)
{
    // Sort the edges in increasing order
    sort(edges.begin(), edges.end(), comparator);

    DSU dsu(V);
    int cost = 0, count = 0;
    // Now traverse this edges in sorted order, take the source - dest - weight, analyze if this source - dest is making a cycle, 
    // if not then add the weight to MST weight, it means now this edge is part of MST
    for (auto& edge: edges)
    {
        int x = edge[0] , y = edge[1] , w = edge[2];
        if (dsu.find(x) != dsu.find(y))
        {
            dsu.unionOfSets(x, y); // MST in making, MST is represented through a DSU data-structure
            cost += w; // Aggregated weight of the whole MST
            if (++count == V-1) break; // Reason: 100 vectices, MST only needs 99 edges, so if 50000 edges as 2 vertices can be connected through multiple edges, 
                                       // Once 99 edges are done, we just have to loop just to see it skip / fail if this condition is not there
        }
    }
    return cost;
}

/*
* Maintain a priority queue to select the edge with min weight
* Push the first vertex
* While the queue is not empty - pull out min weight edge (VlogV), if its unvisited this is going to be added in MST,
* If its added then all its neighbours are now eligible for the candidates from whom the next min will be choosen (Scan through all edges E), 
* so add/update those in the queue (ElogV for binary min heap or E for fibonacci heap) 

* Binary min heap + Adj list = VlogV + E + ElogV = O(ElogV)
* Fibonacci heap = VlogV + E + E = O(E + VlogV)
*/
int primsAlgo(int V, vector<vector<vector<int>>> adj)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> visited(V, false);

    pq.push({0, 0});

    int aggWt = 0;
    while(!pq.empty())
    {
        auto minW = pq.top(); // log V * V cause after removing min there will be re-arrange operation
        pq.pop();

        // because minW is the min element from top of the min heap, so its {weight, vertex} configuration
        int wt = minW.first;
        int vertex = minW.second;

        if (visited[vertex]) continue; // Cause we want to choose min weight edge from those slots which determine unvisited to visited

        aggWt += wt; // Aggregated weight of the MST
        visited[vertex] = true;

        for (auto& neighbour: adj[vertex]) // E
        {
            if (!visited[neighbour[0]]) // only put the unvisited neighbours, so that we can choose min from all of the elements fron min heap
                pq.push({neighbour[1], neighbour[0]}); // log V * E -> after pushing there will be re-arrange operation, push or add / update these 2 operations can be there, but here we are only adding not updating, updating is decrease key operation
        }
    }
    return aggWt;
}