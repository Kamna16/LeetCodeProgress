#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0, ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int remainder = sum%k;
            if(remainder<0) remainder+=k;
            if(mp.find(remainder) != mp.end())
            {
                ans += mp[remainder];
            }
            mp[remainder]++;
        }
        return ans;
    }
};