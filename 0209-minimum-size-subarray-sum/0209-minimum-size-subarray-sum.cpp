class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int ans = INT_MAX;
        int curr =0;
        while(j<n)
        {
            curr += nums[j];
            while(curr >= target)
            {
                ans = min(ans, j-i+1);
                curr -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};