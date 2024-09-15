class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        int count =0;
        int prod = 1;
        while(r<n)
        {
            prod *= nums[r];
            while(l<n && prod >= k)
            {
                if(prod == 1) break;
                prod = prod/nums[l];
                l++;
            }
            if(prod < k)
            {
                count += r-l+1;
            }
            r++;
        }
        return count;
    }
};