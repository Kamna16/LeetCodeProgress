class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int solve(string text1, string text2,int i, int j)
    {
        if(i>= n || j>= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solve(text1,text2,i+1,j+1);
        }
        return dp[i][j] = max(solve(text1,text2,i+1,j), solve(text1,text2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        if(n <= 0 || m <= 0) return 0;
        dp.resize(n+1, vector<int>(m+1,-1));
        return solve(text1,text2,0,0);
    }
};