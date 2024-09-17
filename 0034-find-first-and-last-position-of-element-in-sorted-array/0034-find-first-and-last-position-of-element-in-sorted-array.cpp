class Solution {
public:
    int BS(vector<int> &nums, int s, int e, bool isLeft, int target)
    {
        int ans = -1;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(nums[m] == target)
            {
                ans = m;
                if(isLeft) e = m-1;
                else s = m+1;
            }
            else if(nums[m] < target)
            {
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        int s= 0, e = n-1;
        
        int start = BS(nums,0,n-1,true,target);
        int end = BS(nums,0,n-1,false,target);
        
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
};