class Solution {
public:
    bool check(vector<int>& nums, int k, int mid)
    {
        int arrCount = 1;
        int sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum+nums[i] > mid)
            {
                sum = nums[i];
                arrCount++;
                if(arrCount > k) return false;
            }else{
                sum += nums[i];
            }
            
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(nums,k,mid))
            {
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};