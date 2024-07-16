#include<bits/stdc++.h>
using namespace std;

//1) sort the array and then check for duplicates
//2) use maps to store the frequency

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto pair : mp)
        {
            if(pair.second == 2) ans.push_back(pair.first);
        }
        return ans;
    }
};