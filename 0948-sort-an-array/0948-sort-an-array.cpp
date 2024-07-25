class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>  mp;
        for( int n : nums)
        {
            mp[n]++;
        }
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        int i=0;
        for(int p = mini;p<=maxi;p++)
        {
            while(mp[p]>0)
            {
                nums[i] = p;
                i++;
                mp[p]--;
            }
        }
        return nums;
    }
};