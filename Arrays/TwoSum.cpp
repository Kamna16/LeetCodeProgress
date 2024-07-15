#include<bits/stdc++.h>
using namespace std;

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int find= target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]==find) return {i,j};
            }
        }
        return {};
    }
};

// using maps
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int findNum = target-nums[i];
            if(mp.find(findNum) != mp.end())
            {
                return {mp[findNum],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};