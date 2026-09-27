// Cycle detection: Undirected (Using BFS, DFS => Normal traversal) 
// Directed: (Using DFS: Backtracking, BFS: Kahns Algo, Indegree / Outdegree)

#include <iostream>
#include <vector>
using namespace std;

// ------------------- Undirected graph: DFS ---------------------------
/* If my neighbour is visited & its a parent then cycle exists, because DFS so put recursion if a neighbout is not visited */
bool dfs(int node, vector<vector<int>> graph, vector<int>& visited, int parent)
{
    visited[node] = 1;
    for (int neighbour: graph[node]) // node is the index in the graph vector
    {
        if (!visited[neighbour])
        {
            bool ans = dfs(neighbour, graph, visited, node);
            if (ans) return true; // Subsequent case
        }
        // Base case: If my neighbour is already visited but not parent then I am back to sq one
        // If neighbour is not visited, then dive into its branch through dfs recursion
        else if (visited[neighbour] && neighbour != parent)
            return true;
    }
    return false;
}

// adjList possible in this way as well, each index represents the node and the vector represents list of the vertices it is connected to
// so for a question edgeList can be given eg [[0,4],[1,3],[1,2],[2,4]] or adjList might be given [[4],[2,3],[4]] / {0:[4], 1:[2,3], 2:[4]}
bool isCycle(int V, vector<vector<int>> adjList) 
{
    vector<int> visited(V);
    for(int i=0; i <V; i++)
    {
        // A graph can consist of multiple components, by this visited logic we make sure we're not iterating same comp again & again
        if (!visited[i])
        {
            // Parent is -1 because through this loop we are iterating over every new components of the graph
            bool ans = dfs(i, adjList, visited, -1);
            if (ans) return true;
        }
    }
    return false;
}

// ----------------- Undirected graph: BFS -------------------------------
/* If a neighbout is visited & check if parent of the current node is not that neighbour then its a cycle, because BFS so a parents array */
bool bfs(int source, vector<vector<int>> adjList, vector<int> visited, vector<int> parent)
{
    queue<int> q;
    q.push(source);
    parent.push_back(-1);
    visited[source] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto neighbour: adjList[x])
        {
            if (!visited[neighbour])
            {
                // 3 jobs: 
                // - Mark the neighbour I am visiting as visited
                // - Push the current node as the parent
                // - Push the neighbour so that it can be explored at any of next turn
                visited[neighbour] = 1;
                parent[neighbour] = x;
                q.push(neighbour);
            }
            else {
                if (parent[x] != neighbour) // visited[neighbour] is true
                    return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> adjList)
{
    // Array of parents, because this is a level traversal so one var is not sufficient
    vector<int> visited(V) , parent(V, -1);
    for(int i=0;i<V;i++)
    {
        if (!visited[i])
        {
            bool ans = bfs(i, adjList, visited, parent);
            if (ans) return true;
        }
    }
}

// ---------------------- Directed graph: DFS ------------------------------
/* if a neighbour is visited & it is also in the current path array means there's a cycle + backtracking */


// ---------------------- Cycle detection for Directed graph: BFS (Kahn's Algo) -------------------------
// Also used as a topological sort algo using BFS for direct acyclic graph (DAG)
/* Fact: If indegree of a node is 0, it'll be processed, so in the end if all nodes processed so indegree of all = 0
 *       If there's a node whoose indegree is not 0 in the end or num of processed node < num of total node then there's a cycle
*/
