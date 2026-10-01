// Flood fill algorithm
#include <iostream>
#include <vector>
using namespace std;

// This algo's basic idea is: traversal on grids
/* 
Problem: Starting from (1,1) and changing 1 → 2, I'm at this cell. If it has the old color, change it, then visit its 4 neighbors
1 1 1            2 2 2
1 1 0            2 2 0
1 0 1            2 0 1
And it only changes for adjacent cells connecting the starting node, and if its value same as the starting node, if something is already 2
and we have a 1 after that, we dont go & change that 1, because its already 2, we return 1 (Change) -> 1 (Change) -> 2 (oh already 2, return) -> 1 (Not changed, unless connected to other nodes with 1)
Note, its possible other node with 1 connecting to this node 1 can change it, but if not then it stays 1
*/

void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) 
{
        int m = image.size();
        int n = image[0].size();

        // Out of bounds
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Not part of the region
        if (image[r][c] != oldColor)
            return;

        // Change color
        image[r][c] = newColor;

        // 4 directions, Instead of doing this we can have 2 vectors [1, -1, 0, 0] & [0, 0, 1, -1] & iterate over a loop
        dfs(image, r + 1, c, oldColor, newColor);
        dfs(image, r - 1, c, oldColor, newColor);
        dfs(image, r, c + 1, oldColor, newColor);
        dfs(image, r, c - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
    int oldColor = image[sr][sc];
    // Important: otherwise DFS keeps revisiting the same cells : Explained in top comment
    if (oldColor == color)
        return image;

    dfs(image, sr, sc, oldColor, color); // We can use bfs as well, the main idea is how to traverse on grids, given some constraints
    // For dfs it will go -(right) |(down) _(left) etc. for bfs it will first explore src, then all nodes at L1 neighbour, then all at L2 neighbour etc

    return image;
}