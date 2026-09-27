// edgeList info is given, make graph from it using adjacency list & adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

void print_graph(vector<vector<int>> graph)
{
    int n = graph.size();
    for (int i=0; i<n; i++)
    {
        cout<<"Node: "<< i<<"Neighbours: ";
        for (int j=0; j<n; j++)
        {
            if (graph[i][j] == 1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print_graph(unordered_map<int, vector<int>> graph)
{
    for (auto x: graph)
    {
        cout<<"Node: "<< x.first<<"Neighbours: ";
        for (auto y: x.second)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void implWithAdjMatrix(vector<vector<int>>& edgeList)
{
    // Defining a n * n matrix
    int n = edgeList.size();
    vector<vector<int>> adjMatrix(n, vector<int>(n,0));
    for(int i=0; i<=edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1]; // Because edgeList is a 1:1 connection
        
        // Un-directed graph hence both, for directed graph only 1 in that direction is sufficient
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }
    print_graph(adjMatrix); // This adjMatrix is the graph itself
}

void implWithAdjList(vector<vector<int>>& edgeList)
{
    // Defining a adj list
    std::unordered_map<int, vector<int>> adjList;
    for(int i=0; i<=edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1];
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    print_graph(adjList);
}