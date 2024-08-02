class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(row == grid.size()-1 && col == grid[0].size()-1) return grid[row][col];
        
        if(dp[row][col]) return dp[row][col];

        if(col == grid[0].size()-1)
        {
            return dp[row][col] = grid[row][col] + solve(row+1,col,grid,dp);
        }
        else if(row == grid.size()-1)
        {
            return dp[row][col] = grid[row][col] + solve(row,col+1,grid,dp);
        }
        else return dp[row][col] = grid[row][col] + min(solve(row+1,col,grid,dp), solve(row,col+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        return solve(0,0,grid,dp);
    }
};