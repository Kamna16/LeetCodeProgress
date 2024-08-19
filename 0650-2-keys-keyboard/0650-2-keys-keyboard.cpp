class Solution {
public:
    int dp[1001][1001];
    int solve(int n, int currA, int clipBoardA)
    {
        if(currA == n) return 0;
        if(currA > n) return 100000;
        if(dp[currA][clipBoardA] != -1) return dp[currA][clipBoardA];
        int CopyPaste = 1+1+solve(n, currA + currA,currA); 
        int Paste = 1+solve(n, currA + clipBoardA,clipBoardA); 
        return dp[currA][clipBoardA] = min(CopyPaste ,Paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        memset(dp,-1,sizeof(dp));
        return 1+solve(n,1,1); 
    }
};