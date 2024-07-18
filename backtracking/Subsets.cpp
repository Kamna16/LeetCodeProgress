#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, vector<int> &temp)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,i+1,temp);
        temp.pop_back();
        solve(nums,i+1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        return ans;
    }
};