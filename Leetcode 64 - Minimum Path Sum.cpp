#include <bits/stdc++.h>

// Iterative approach to the solution (without memo)
// Fails because time limit exceeded
// For AC solution go to line 27

int best = INT_MAX;

void calculateBestRoute(vector<vector<int>> &grid, int x, int y, int current){
    if(x == grid.size()-1 && y == grid[x].size()-1){
        current += grid[x][y];
        best = current < best ? current : best; 
    }
    if(y != grid[x].size()-1){
        calculateBestRoute(grid, x, y+1, grid[x][y] + current);
    }
    if(x != grid.size()-1){
        calculateBestRoute(grid, x+1, y, grid[x][y] + current);
    }
}

int minPathSum(vector<vector<int>> &grid){
    calculateBestRoute(grid, 0, 0, 0);
    return best;
}

// Looping approach (with memo)

int minPathSum(vector<vector<int>>& grid) {
    vector<int> memo(grid.size() * grid[0].size(), INT_MAX);
    const int rowSize = grid[0].size();
    for(int x = 0; x < grid.size(); x++){
        for(int y = 0; y < grid[x].size(); y++){
            // Top left element
            if(x == 0 && y == 0){
                memo[0] = grid[0][0];
            }
            // Top row
            else if(x == 0){
                // current + from left
                memo[y] = grid[0][y] + memo[y-1];
            }
            // First column
            else if(y == 0){
                // current + from above
                memo[x * rowSize] = grid[x][0] + memo[(x-1) * rowSize];
            }
            // Anything else
            else{
                // current val = min(from top + current, from left + current)
                memo[x * rowSize + y] = min(grid[x][y] + memo[(x-1) * rowSize + y], grid[x][y] + memo[x * rowSize + (y-1)]);
            }
        }
    }
    return memo.back();
}