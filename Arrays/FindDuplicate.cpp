#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/

// using sort method
// O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
    }
};

// hare and tortoise method (slow and fast pointer)
// if(sow == fast) --> there is a cycle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow=nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};