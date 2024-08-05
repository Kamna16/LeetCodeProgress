#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int longestCommonSubstr(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int maxLength = 0;
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                maxLength = max(maxLength, solve(s1, s2, i, j));
            }
        }
        return maxLength;
    }
};
