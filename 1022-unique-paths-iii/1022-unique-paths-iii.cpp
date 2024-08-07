class Solution {
public:
    int non_obstacleCount =1;
    int result =0;
    int n,m;
    void dfs(int i,int j, int nc, vector<vector<int>>& grid)
    {
      if(i<0 || i>=n || j<0 ||j>=m || grid[i][j] == -1) return;

      if(grid[i][j] == 2)
      {
        if(nc == non_obstacleCount) result++;
        return;
      }
      grid[i][j] =-1;
      dfs(i+1,j,nc+1,grid);
      dfs(i-1,j,nc+1,grid);
      dfs(i,j+1,nc+1,grid);
      dfs(i,j-1,nc+1,grid);
      grid[i][j] =0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int startingR =0;
        int startingC =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0) non_obstacleCount++;
                if(grid[i][j] == 1){
                    startingR = i;
                    startingC = j;
                }
            }
        }
        dfs(startingR, startingC,0, grid);
        return result;

    }
};