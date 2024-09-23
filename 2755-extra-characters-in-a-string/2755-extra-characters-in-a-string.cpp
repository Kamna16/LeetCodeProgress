class Solution {
public:
    vector<int> dp;
    int solve(int i, unordered_set<string> &st, string &s, int n)
    {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int res = 1+ solve(i+1,st,s,n);
        for(int j=i;j<n;j++)
        {
            string curr = s.substr(i,j-i+1);
            if(st.count(curr))
            {
                res = min(res,solve(j+1,st,s,n));
            }
        }
        return dp[i] = res;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        dp.resize(n,-1);
        unordered_set<string> st(dict.begin(),dict.end());
        return solve(0,st,s,n);
    }
};