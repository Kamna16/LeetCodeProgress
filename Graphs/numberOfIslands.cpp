#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || visited[i][j]) return;

        visited[i][j] = true;

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]&& grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};