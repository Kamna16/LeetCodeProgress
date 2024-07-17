#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[46] = {0};
    int climbStairs(int n) {
        if(n <=1) return 1;
        if(dp[n]) return dp[n];
        int oneStep = climbStairs(n-1);
        int twoStep = climbStairs(n-2);

        return dp[n] = oneStep+twoStep;
    }
};