#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  vector<bool> vis;
    void solve(int V, vector<int> adj[], vector<int> &ans, int u)
    {
        if(vis[u]) return;
        vis[u]=true;
        ans.push_back(u);
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                solve(V,adj,ans,v);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vis.resize(V, false);
        solve(V, adj, ans,0);
        return ans;
    }
};