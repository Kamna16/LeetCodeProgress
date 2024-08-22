class Solution {
public:
    int n;

    bool isSafe(int i, int j, char num, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == num) return false;
            if (board[k][j] == num) return false;
      
            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(i, j, num, board)) {
                            board[i][j] = num; 
                            if (solve(board)) 
                                return true;
                            board[i][j] = '.';  
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        n = board.size(); 
        solve(board);
    }
};
