// edgeList info is given, make graph from it, then traverse & print using BFS & DFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Using BFS
vector<int> bfs(int source, unordered_map<int, vector<int>>& graph, int n)
{
    queue<int> q;
    vector<int> visited(n+1);
    vector<int> res;

    // Insert the initial, mark it visited
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        res.push_back(x);
        for (auto i: graph[x])
        {
            if (!visited[i])
            {
                // Insert so that we can pick it & traverse its neighbours
                q.push(i);
                // Mark it visited
                visited[i] = 1;
            }
        }
    }
    return res; // Returning ans with traversal order
}

// Using DFS
void dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& visited)
{   
    cout<<node<<" "; // So traversal order gets printed
    visited[node] = 1;

    for(int neighbour: graph[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, graph, visited);
    }
}

// Using BFS T.C. = b^(d+1) - 1 / b - 1, S.C. = b^d where b = branch factor i.e., num of children , d = depth
// S.C. is b^d considering max num of elements need to be stored in queue so that is the num of children from the last level
// T.C. ~ b^d

// Using DFS T.C. = b^d, S.C. = d -> This is recursion stack depth

// For BFS, DFS: T.C. Using adj list = V+E, Using adj matrix = V^2
// S.C. for both its V, for bfs its queue, for dfs its recursion stack or actual stack if used