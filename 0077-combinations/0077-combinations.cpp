class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, vector<int> &curr,int idx)
    {
        if(curr.size() == k)
        {
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<=n;i++)
        {
            if(find(curr.begin(),curr.end(), i) != curr.end()) continue;
            curr.push_back(i);
            solve(n,k,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n,k,curr,1);
        
        return ans;
    }
};