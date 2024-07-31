class Solution {
public:
    int WIDTH;
    int dp[1001][1001];
    int solve(int i, vector<vector<int>>& books, int remainingWidth,int maxHeight)
    {
        if(i>= books.size()) return maxHeight;
        if(dp[i][remainingWidth] != -1) return dp[i][remainingWidth];
        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep=INT_MAX, skip=INT_MAX;
        if(bookW <= remainingWidth){
            keep = solve(i+1,books,remainingWidth-bookW,max(maxHeight,bookH));
        }
        skip = maxHeight + solve(i+1,books,WIDTH-bookW,bookH);
        return dp[i][remainingWidth] = min(keep,skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        WIDTH = shelfWidth;
        return solve(0,books,shelfWidth,0);
    }
};