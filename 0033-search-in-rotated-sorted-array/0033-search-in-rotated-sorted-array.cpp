class Solution {
public:
    int findPivot(vector<int>& nums) {
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
        return e;
    }
    int BS(vector<int>& nums, int target, int s, int e)
    {
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(nums[m] == target) return m;
            else if(nums[m] < target)
            {
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s =0, e = n-1;
        int pivot = findPivot(nums);
        int left = BS(nums,target,0,pivot-1);
        int right = BS(nums,target,pivot,n-1);

        if(left == -1) return right;
        return left;
    }
};