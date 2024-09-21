class Solution {
public:
    void solve(int n, vector<int> &ans, int curr)
    {
        if(curr > n ) return;
        ans.push_back(curr);
        for(int i=0;i<=9;i++)
        {
            int currNum = curr*10 + i;
            solve(n,ans,currNum);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            solve(n,ans,i);
        }
        return ans;
    }
};