#include<bits/stdc++.h>
using namespace std;

// sorting method
// considering -ve numbers
// negative + negative = positive
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
		sort(nums.begin(), nums.end());
		return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
	}

};