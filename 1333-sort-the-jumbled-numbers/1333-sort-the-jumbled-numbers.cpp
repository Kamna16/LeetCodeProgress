class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            string curr = to_string(nums[i]);
            string newNum = "";
            for(int j=0;j<curr.length();j++)
            {
                newNum += to_string(mapping[curr[j]-'0']);
            }
            mp.push_back({stoi(newNum),i});
        }
        sort(mp.begin(),mp.end());
        vector<int> ans;
        for(auto p : mp)
        {
            int ind = p.second;
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};