// Shortest Path: 
// Single Source Shortest Path: Finds source to all destination (Unweighted: BFS ; Weighted: +ve(Dijkstra) , -ve(Bellman Ford)) -> Works for both directed + un-directed
// All Source Shortest Path: Finds source to all destination treating all nodes as source, handles -ve weight as well (Floyd Warshall)
#include <iostream>
#include <vector>
using namespace std;

// Dijkstra Algo
vector<int> shortestPathDijkstra(vector<vector<pair<int, int>>>& adjList, int src)
{
    // Nature of pair is {distance, node} so that min heap can quickly judge based on min distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    int n = adjList.size();
    vector<int> distance(n, INT_MAX); // Declare a distance vector & initialize with infinity

    // Push the sources into
    distance[src] = 0;
    pq.push({0, src});

    // Now start comparing, 
    // Basic idea is: Take node with min dist from queue, 
    // For all its neighbour, check if current distance < previous distance, 
    // if so, then push that neighbout with updated dist, also update the dist array
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int node = x.second; // Because we took the min element from the min heap, now there the manner is {distance, node}

        for (auto& neighbour: adjList[node])
        {
            // For adjList its normal {node, weight}
            int neighbourNode = neighbour.first;
            int prev_dist = distance[neighbourNode];
            int weight = neighbour.second;

            int curr_dist = prev_dist + weight;

            if (curr_dist < prev_dist)
            {
                pq.push({curr_dist, neighbourNode});
                distance[neighbourNode] = curr_dist;
            }
        }
    }

    // Now the distance array contains all the shortest distance from source for all nodes, 
    // so if something's dist is still infinity then its not reachable
    for (auto dist: distance)
    {
        if (dist == INT_MAX)
            dist = -1;
    }

    return distance;
}

// Dijkstra can do for -ve weights but the time increases because it will repeat a node more than once, 
// for -ve weight cycles where total is -ve as well, it will TLE cause it will go in loop, hence comes Bellman Ford
// Diff b/w Dijkstra and Bellman Ford is that: Dijkstra chooses the next node with min distance, Bellman Ford iterate over all nodes V-1 times
// Dijsktra T.C. = O(V + ElogV) , Bellman Ford T.C. = O(V^2)

// Bellman Ford
vector<int> shortestPathBF(vector<vector<pair<int, int>>>& adjList, int src)
{
    int n = adjList.size();
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // Updation in the distances array for all V nodes
    for(int i=0; i<n; i++)
    {
        for(auto& neighbours: adjList[i])
        {
            int neighbourNode = neighbours.first;
            int weight = neighbours.second;
            int prev_dist = distance[neighbourNode];
            int curr_dist = prev_dist + weight;

            if (curr_dist < prev_dist)
                distance[neighbourNode] = curr_dist;
        }
    }
    // At this point you should have all node's min dist from source in the dist array

    // Now check one more time, if it still decreases, reachable -ve edge cycle exists
    // There is no algo to determine min path distance for graph with -ve edge cycle, cause it will run infinite times
    for(int i=0; i<n; i++)
    {
        for(auto& neighbours: adjList[i])
        {
            int neighbourNode = neighbours.first;
            int weight = neighbours.second;
            int prev_dist = distance[neighbourNode];

            if (prev_dist == INT_MAX) continue;

            int curr_dist = prev_dist + weight;
            if (curr_dist < prev_dist)
                return {-1};
        }
    }

    for (auto dist: distance)
    {
        if (dist == INT_MAX)
            dist = -1;
    }
    return distance;
}


// Floyd Warshall Algo
// If its not a distanceMatrix -> then from edgeList make the distance matrix, for direct edges put weight, for indirect put infinity
vector<vector<int>> shortestPathFloydWarshall(vector<vector<int>>& distanceMatrix)
{
    // Step 1: Do it for all nodes, all the variables will change, src, dest, intermediate node so cubic T.C.
    int n = distanceMatrix.size();
    for (int k = 0; k<n; k++) // for each intermediate node
    {
        for (int i = 0; i<n; i++) // hold on to source
        {
            for (int j = 0; j<n; j++) // then iterate for all dest
            {
                if (distanceMatrix[i][k] == INT_MAX || distanceMatrix[k][j] == INT_MAX) continue;
                int dist_through_k = distanceMatrix[i][k] + distanceMatrix[k][j];
                if (dist_through_k < distanceMatrix[i][j]) distanceMatrix[i][j] = dist_through_k;
            }
        }
    }

    // Step 2: Check one more time, like Bellman Ford if it still decreases, then -ve weight cycle is present
    // Its like applying BF but for each node so O(VE) * V ~ O(V^3)
    for (int k = 0; k<n; k++) // for each intermediate node
    {
        for (int i = 0; i<n; i++) // hold on to source
        {
            for (int j = 0; j<n; j++) // then iterate for all dest
            {
                if (distanceMatrix[i][k] == INT_MAX || distanceMatrix[k][j] == INT_MAX) continue;
                int dist_through_k = distanceMatrix[i][k] + distanceMatrix[k][j];

                if (dist_through_k < distanceMatrix[i][j]) return {{-1}};
            }
        }
    }

    for (auto dist: distanceMatrix)
    {
        for (auto eleDist: dist)
        {
            if (eleDist == INT_MAX)
            eleDist = -1;
        }
    }
    return distanceMatrix;
}