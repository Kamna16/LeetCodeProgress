class Solution {
public:
    vector<vector<bool>> visited;
    int n;
    int m;
    int noOfIslands(vector<vector<int>>& grid)
    {
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid, int i,int j)
    {
        if(i < 0 || j<0 || i>=n || j>=m || grid[i][j] == 0 || visited[i][j]) return;
        visited[i][j] = true;

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        int count = noOfIslands(grid);
        if(count > 1 || count == 0 ) return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    visited.clear();
                    visited.resize(n, vector<bool>(m, false));
                    int cnt = noOfIslands(grid);
                    if(cnt >1 || cnt == 0) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};