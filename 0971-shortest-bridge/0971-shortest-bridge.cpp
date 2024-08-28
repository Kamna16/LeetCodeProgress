#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<bool>> vis;

    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& island) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == 0) return;
        vis[i][j] = true;
        island.push_back({i, j});

        dfs(i + 1, j, grid, island);
        dfs(i, j + 1, grid, island);
        dfs(i - 1, j, grid, island);
        dfs(i, j - 1, grid, island);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vis.resize(n, vector<bool>(n, false));
        vector<pair<int, int>> firstIsland;

        bool found = false;
        for(int i = 0; i < n; i++) {
            if(found) break;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, grid, firstIsland);
                    found = true;
                    break;
                }
            }
        }

        queue<pair<int, int>> q;
        for(auto cell : firstIsland) {
            q.push(cell);
        }

        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(auto cell : firstIsland) {
            visited[cell.first][cell.second] = true;
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;

                // Check all 4 directions
                for(auto [di, dj] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj]) {
                        if(grid[ni][nj] == 1) return count;
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                    }
                }
            }
            count++;
        }

        return -1; 
    }
};
