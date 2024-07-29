class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int r, int c, vector<string> &board)
    {
        for(int i=r-1;i>=0;i--)
        {
            if(board[i][c] == 'Q') return false;
        }
        for(int i=r-1, j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        for(int i=r-1,j=c+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row)
    {
        if(row >= board.size())
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<board.size();col++)
        {
            if(isValid(row,col,board))
            {
                board[row][col] = 'Q';
                solve(board,row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board, 0);
        return ans;
    }
};