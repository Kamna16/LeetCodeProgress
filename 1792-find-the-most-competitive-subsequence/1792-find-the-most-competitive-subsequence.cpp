class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[i] < nums[st.top()] && st.size() + (n - i) > k) {
                st.pop();
            }
            
            if (st.size() < k) {
                st.push(i);
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(nums[st.top()]);
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};