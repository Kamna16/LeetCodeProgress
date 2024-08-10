class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &newGrid) {
        int n = newGrid.size();
        stack<pair<int, int>> s;
        s.push({i, j});

        while (!s.empty()) {
            auto [x, y] = s.top();
            s.pop();

            if (x < 0 || y < 0 || x >= n || y >= n || newGrid[x][y] == 0) 
                continue;

            newGrid[x][y] = 0;

            s.push({x + 1, y});
            s.push({x - 1, y});
            s.push({x, y + 1});
            s.push({x, y - 1});
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> newGrid(n * 3, vector<int>(n * 3, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    newGrid[i * 3][j * 3 + 2] = newGrid[i * 3 + 1][j * 3 + 1] = newGrid[i * 3 + 2][j * 3] = 0;
                }
                if (grid[i][j] == '\\') {
                    newGrid[i * 3][j * 3] = newGrid[i * 3 + 1][j * 3 + 1] = newGrid[i * 3 + 2][j * 3 + 2] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (newGrid[i][j] == 1) {
                    ans++;
                    dfs(i, j, newGrid);
                }
            }
        }
        return ans;
    }
};
