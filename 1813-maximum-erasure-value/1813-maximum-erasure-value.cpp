class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i=0, j=0;
        int currSum = 0;
        int maxi = 0;
        while(j<n)
        {
            if(st.find(nums[j]) == st.end())
            {
                currSum+= nums[j];
                st.insert(nums[j]);
                maxi = max(maxi, currSum);
                j++;
            }else{
                currSum -= nums[i];
                st.erase(nums[i]);
                i++;  
            }
            
            
        }
        return maxi;
    }
};