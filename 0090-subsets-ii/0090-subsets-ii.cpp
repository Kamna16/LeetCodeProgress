class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void recur(vector<int>& nums, int ind)
    {
        ans.push_back(sub);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i] == nums[i-1]) continue;
            sub.push_back(nums[i]);
            recur(nums,i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recur(nums,0);
        return ans;
    }
};