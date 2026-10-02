#include <iostream>
#include <vector>
using namespace std;

class DSU
{
private:
    vector<int> parent; // Node's immediate predecessor
    vector<int> rank; // Height of the tree which represent the sets
public:
    DSU(int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
    }
    
    // This is a function to find group leader
    int find(int node)
    {
        if (parent[node] == node) return node;
        // The parent that we found through recursion put that in the actual parent position for the node, 
        // so that we can find in O(1) time next time
        return parent[node] = find(parent[node]); // Optimization technique: Path Compression
    }

    void unionOfSets(int a, int b)
    {
        int leader_of_a = find(a);
        int leader_of_b = find(b);

        if (leader_of_a != leader_of_b)
        {
            // Optimization technique: Union by rank
            if (rank[leader_of_a] < rank[leader_of_b])
            {
                // b is coming from larger group, merge a's group with b's group
                parent[leader_of_a] = leader_of_b;
                rank[leader_of_b] += rank[leader_of_a];
            }
            else
            {
                // else a is part of larger group, merge b's group with a's group
                parent[leader_of_b] = leader_of_a;
                rank[leader_of_a] += rank[leader_of_b];
            }
        }
    }
};