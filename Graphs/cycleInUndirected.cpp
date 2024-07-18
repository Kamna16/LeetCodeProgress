#include<bits/stdc++.h>
using namespace std;

// using DFS
class Solution {
  public:
    bool dfs(int V, vector<int> adj[],int u,vector<bool> &vis,int parent)
    {
        vis[u] = true;
        for(int v : adj[u])
        {
            if(v == parent) continue;
            if(vis[v]) return true;
            if(dfs(V,adj,v,vis,u)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dfs(V,adj,i,vis,-1)) return true;
        }
        return false;
    }
};