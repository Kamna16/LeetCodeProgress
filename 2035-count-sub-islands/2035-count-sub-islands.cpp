class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        if(i < 0 || i >= n || j < 0 || j >= m) return true;
        if(grid2[i][j] == 0 || vis[i][j]) return true;
        vis[i][j] = true;

        bool res = (grid1[i][j] == 1);
        res = res & dfs(i+1,j,grid1,grid2);
        res = res & dfs(i,j+1,grid1,grid2);
        res = res & dfs(i-1,j,grid1,grid2);
        res = res & dfs(i,j-1,grid1,grid2);
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        vis.resize(n,vector<bool>(m,false));
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j] == 1 && !vis[i][j])
                {
                    if(dfs(i,j,grid1,grid2)) count++;
                }
            }
        }
        return count;
    }
};