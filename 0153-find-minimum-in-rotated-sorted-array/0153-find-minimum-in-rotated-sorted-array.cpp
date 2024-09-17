class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e=n-1;
        while(s<e)
        {
            int m = s+(e-s)/2;
            if(nums[m] > nums[e])
            {
                s = m+1;
            }else e = m;
        }
        return nums[e];
    }
};