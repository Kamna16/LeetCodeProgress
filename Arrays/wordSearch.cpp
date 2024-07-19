#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
    int n, m;

    bool backtrack(vector<vector<char>>& board, const string &word, int r, int c, int i) {
        if (i == word.size()) return true;
        if (r < 0 || c < 0 || r >= n || c >= m || board[r][c] == '$' || board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '$';  // Mark the cell as visited

        for (auto& direction : dir) {
            int new_r = r + direction[0];
            int new_c = c + direction[1];
            if (backtrack(board, word, new_r, new_c, i + 1)) return true;
        }

        board[r][c] = temp;  // Unmark the cell
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false; // Handle edge cases

        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
