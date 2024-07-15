#include<bits/stdc++.h>
using namespace std;

//1) using maps -> return max frequency element
//2) using sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};