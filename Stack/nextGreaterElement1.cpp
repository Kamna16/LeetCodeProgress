#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<n1;i++)// for nums1
        {
            int curr = nums1[i];
            int currGreater = -1;
            if(mp.find(curr) != mp.end())
            {
                for(int j=mp[curr]+1;j<n2;j++)
                {
                    if(nums2[j] > curr)
                    {
                        currGreater = nums2[j];
                        break;
                    }
                }
            }
            ans.push_back(currGreater);
        }
        return ans;
    }
};

// using monotonic stack
class Solution {
public:
    unordered_map<int,int> mp;
    void storeNextGreater(vector<int>& nums)
    {
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            int res = st.empty() ? -1 : st.top();
            st.push(nums[i]);
            mp[nums[i]] = res;
        }
    
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size();
        storeNextGreater(nums2);
        for(int i=0;i<n1;i++)
        {
            ans.push_back(mp[nums1[i]]);
        } 
        return ans;
    }
};