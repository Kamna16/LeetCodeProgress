class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<string>& strs, int m, int n, int idx)
    {
        if(idx >= strs.size()) return 0;
        if(dp[m][n][idx] != -1) return dp[m][n][idx];
        int oneCount = count(strs[idx].begin(),strs[idx].end(),'1');
        int zeroCount = strs[idx].size()-oneCount;

        
        int not_take = solve(strs,m, n,idx+1);

        if(m-zeroCount >=0 && n-oneCount >= 0)
        {
            int take = 1 + solve(strs,m-zeroCount, n-oneCount,idx+1);
            return dp[m][n][idx] = max(take, not_take);
        }
        return dp[m][n][idx] = not_take;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(), -1)));
        return solve(strs,m,n,0);
    }
};