// SCC: A SCC is a maximal group of vertices in a directed graph where every vertex can reach every other vertex
// edges: A -> B , B -> C , C -> A ; C -> D ; D -> E , E -> D ; SCCs are: {A, B, C} , {D, E}
// Both Kosaraju and Tarjan's algo help us to find SCCs from a graph
#include <iostream>
#include <vector>
using namespace std;

/*
* Kosaraju's Algo: 
*   Run DFS & record finish time order so a stack had the order
*   Reverse all the edges (transpose graph)
*   Pop the vertices from stack one by one, and run DFS on it if not visited, if we can reach other vertices through one DFS then these vertices form one SCC
*   T.C. = All stages are O(V + E) ~ O(V + E)
*/
vector<vector<int>> kosarajuAlgo()
{

}

/*
* Tarjan's Algo:
*   
*/
vector<vector<int>> tarjanAlgo()
{

}