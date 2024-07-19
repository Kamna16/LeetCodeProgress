#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
       int n = nums.size();
       int lsum =0;
       int rsum =0;
       for(int i=0;i<k;i++)
       {
            lsum+= nums[i];
       }
       int maxSum = lsum;
       int r = n-1;
       for(int i=k-1;i>=0;i--)
       {
            lsum -= nums[i];
            rsum += nums[r];
            r--;
            maxSum = max(maxSum,lsum+rsum);
       }
       return maxSum;
    }
};