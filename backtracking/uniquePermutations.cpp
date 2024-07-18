#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void backtrack(vector<vector<int>> &ans,vector<int> &temp,unordered_map<int,int> &mp)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        for(auto &pair:mp)
        {
            int num = pair.first;
            int count = pair.second;
            if(count==0) continue;

            // do something
            temp.push_back(num);
            mp[num]--;

            // explore it
            backtrack(ans,temp,mp);

            // undo it
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        n= nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        backtrack(ans,temp,mp);
        return ans;
    }
};

// approach 2 swapping method --> using set to track unique elements
class Solution {
public:
    int n;
    void backtrack(vector<int>& nums,vector<vector<int>> &ans,int idx)
    {
        if(idx == n)
        {
            ans.push_back(nums);
            return;
        }
        set<int> st;
        for(int i=idx;i<n;i++)
        {
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            backtrack(nums,ans,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        n= nums.size();
        backtrack(nums,ans,0);
        return ans;
    }
};