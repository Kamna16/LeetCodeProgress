class Solution {
public:
    vector<int> ans;
    void dfs(int start,int prev, unordered_map<int,vector<int>> &mp)
    {
        ans.push_back(start);
        for(auto n : mp[start])
        {
            if(n != prev)
            {
                dfs(n,start, mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        if(n == 1) return adjacentPairs[0];
        unordered_map<int,vector<int>> mp;
        int maxNode = INT_MIN;

        for(int i=0;i<n;i++)
        {
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);

             maxNode = max(maxNode, max(u, v));
        }
        int start = -1;
        for(auto p : mp)
        {
            if(p.second.size() == 1)
            {
                start = p.first;
                break;
            }
        }
        dfs(start,INT_MAX, mp);
        return ans;
    }
};