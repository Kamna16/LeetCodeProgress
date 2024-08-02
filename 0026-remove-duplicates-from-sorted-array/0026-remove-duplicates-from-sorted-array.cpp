class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=1;
        while(j<n)
        {
            if(nums[j] == nums[i]) j++;
            else{
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};