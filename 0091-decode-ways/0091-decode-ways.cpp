class Solution {
public:
    int dp[101];
    int solve(string s,int i)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int opt1 = solve(s,i+1);
        int opt2 = 0;
        if(i+1<s.size())
        {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
            opt2 = solve(s,i+2);
        }
        

        return dp[i] = opt1+opt2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
    }
};