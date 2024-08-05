class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<unordered_map<int, int>> playerColorCount(n);

        for (auto p : pick) {
            int player = p[0];
            int color = p[1];
            playerColorCount[player][color]++;
        }

        int winningPlayers = 0;

        for (int i = 0; i < n; ++i) {
            for (auto entry : playerColorCount[i]) {
                if (entry.second > i) {
                    winningPlayers++;
                    break;
                }
            }
        }

        return winningPlayers;
    }
};