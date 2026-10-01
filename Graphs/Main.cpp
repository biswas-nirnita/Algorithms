#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <utility>
#include <functional>
using namespace std;

/*
    Main driver for the graph files.

    Before compiling, fix the duplicate function names in CycleDetection.cpp:
      - isCycleUndirectedDFS
      - isCycleUndirectedBFS
      - isCycleDirectedDFS

    Also fix the implementation issues noted in the review.
*/

// GraphImpl.cpp
void implWithAdjMatrix(vector<vector<int>>& edgeList);
void implWithAdjList(vector<vector<int>>& edgeList);

// GraphTraversal.cpp
vector<int> bfs(int source, unordered_map<int, vector<int>>& graph, int n);
void dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited);

// CycleDetection.cpp (recommended renamed functions)
bool isCycleUndirectedDFS(int V, vector<vector<int>>& adjList);
bool isCycleUndirectedBFS(int V, vector<vector<int>>& adjList);
bool isCycleDirectedDFS(int V, vector<vector<int>>& adjList);
vector<int> topoSort(int V, vector<vector<int>>& adjList);

// ShortestPathAlogs.cpp
vector<int> shortestPathDijkstra(vector<vector<pair<int, int>>>& adjList, int src);
vector<int> shortestPathBF(vector<vector<pair<int, int>>>& adjList, int src);
vector<vector<int>> shortestPathFloydWarshall(vector<vector<int>>& distanceMatrix);

// TraversalOnGrids.cpp
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);

void printVector(const vector<int>& v)
{
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

void printMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (int x : row)
        {
            if (x == INT_MAX)
                cout << "INF ";
            else
                cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // ============================================================
    // 1. Graph representation
    // ============================================================
    cout << "===== GRAPH REPRESENTATION =====\n";

    vector<vector<int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };

    // These calls require GraphImpl.cpp to be corrected as noted.
    implWithAdjMatrix(edgeList);
    implWithAdjList(edgeList);

    // ============================================================
    // 2. BFS / DFS
    // ============================================================
    cout << "\n===== BFS / DFS =====\n";

    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3};
    graph[3] = {2};

    cout << "BFS: ";
    printVector(bfs(0, graph, 4));

    cout << "DFS: ";
    vector<int> visited(4, 0);
    dfs(0, graph, visited);
    cout << "\n";

    // ============================================================
    // 3. Cycle detection
    // ============================================================
    cout << "\n===== CYCLE DETECTION =====\n";

    vector<vector<int>> undirectedGraph = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2}
    };

    cout << "Undirected DFS cycle: "
         << (isCycleUndirectedDFS(4, undirectedGraph) ? "YES" : "NO")
         << "\n";

    cout << "Undirected BFS cycle: "
         << (isCycleUndirectedBFS(4, undirectedGraph) ? "YES" : "NO")
         << "\n";

    vector<vector<int>> directedGraph = {
        {1},
        {2},
        {0, 3},
        {}
    };

    cout << "Directed DFS cycle: "
         << (isCycleDirectedDFS(4, directedGraph) ? "YES" : "NO")
         << "\n";

    // ============================================================
    // 4. Topological sort / Kahn's algorithm
    // ============================================================
    cout << "\n===== TOPOLOGICAL SORT =====\n";

    vector<vector<int>> dag = {
        {1, 2},
        {3},
        {3},
        {}
    };

    cout << "Topological order: ";
    printVector(topoSort(4, dag));

    // ============================================================
    // 5. Dijkstra
    // ============================================================
    cout << "\n===== DIJKSTRA =====\n";

    vector<vector<pair<int, int>>> weightedGraph(4);

    auto addUndirectedEdge =
        [&](int u, int v, int w)
        {
            weightedGraph[u].push_back({v, w});
            weightedGraph[v].push_back({u, w});
        };

    addUndirectedEdge(0, 1, 3);
    addUndirectedEdge(0, 2, 4);
    addUndirectedEdge(1, 2, 1);
    addUndirectedEdge(2, 3, 2);

    cout << "Distances from source 0: ";
    printVector(shortestPathDijkstra(weightedGraph, 0));

    // ============================================================
    // 6. Bellman-Ford
    // ============================================================
    cout << "\n===== BELLMAN-FORD =====\n";

    // Directed graph with a negative edge but no negative cycle.
    vector<vector<pair<int, int>>> bfGraph(4);

    bfGraph[0].push_back({1, 3});
    bfGraph[0].push_back({2, 4});
    bfGraph[1].push_back({2, -1});
    bfGraph[2].push_back({3, 2});

    cout << "Distances from source 0: ";
    printVector(shortestPathBF(bfGraph, 0));

    // ============================================================
    // 7. Floyd-Warshall
    // ============================================================
    cout << "\n===== FLOYD-WARSHALL =====\n";

    const int INF = INT_MAX;

    vector<vector<int>> distanceMatrix = {
        {0,   3,   4,   INF},
        {INF, 0,   -1,  INF},
        {INF, INF, 0,   2},
        {INF, INF, INF, 0}
    };

    vector<vector<int>> allPairs =
        shortestPathFloydWarshall(distanceMatrix);

    printMatrix(allPairs);

    // ============================================================
    // 8. Flood Fill
    // ============================================================
    cout << "\n===== FLOOD FILL =====\n";

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> filledImage =
        floodFill(image, 1, 1, 2);

    printMatrix(filledImage);

    return 0;
}
