class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int src = queries[i][0];
            int dest = queries[i][1];
            int XOR = 0;
            for(int i=src;i<=dest;i++)
            {
                XOR ^= arr[i];
            }
            ans[i] = XOR;
        }
        return ans;
    }
};