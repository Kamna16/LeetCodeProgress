#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<bool> vis(V,false);
        vector<int> ans;
        q.push(0);
        vis[0] = true;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int n : adj[node])
            {
                if(!vis[n])
                {
                    q.push(n);
                    vis[n] = true;
                }
            }
        }
        return ans;
    }
};
