class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, vector<int> &curr,int i)
    {
        if(curr.size() == k)
        {
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
            return;
        }
        if(i > n) return;

        curr.push_back(i);
        solve(n,k,curr,i+1);
        curr.pop_back();
        solve(n,k,curr,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n,k,curr,1);
        
        return ans;
    }
};