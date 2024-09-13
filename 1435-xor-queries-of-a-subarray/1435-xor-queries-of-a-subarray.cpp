class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = arr.size();
        vector<int> ans;
        vector<int> PreXor(m);
        PreXor[0] = arr[0];
        for(int i=1;i<m;i++)
        {
            PreXor[i] = PreXor[i-1]^arr[i];
        }
        for(int i=0;i<n;i++)
        {
            int src = queries[i][0];
            int dest = queries[i][1];
            int calc = PreXor[dest]^ (src == 0 ? 0 : PreXor[src-1]);
            ans.push_back(calc);
        }
        return ans;
    }
};