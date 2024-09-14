class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int max_ans = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                count++; 
                max_ans = max(max_ans, count);
            } else {
                count = 0; 
            }
        }

        return max_ans;
    }
};
