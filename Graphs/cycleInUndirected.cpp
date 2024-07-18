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

// using bfs
class Solution {
    private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neighbour : adj[node])
            {
                if(!vis[neighbour])
                {
                    vis[neighbour] =1;
                    q.push({neighbour, node});
                }
                else if(parent != neighbour)
                {
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0};
       // considering multiple components
       for(int i=0; i<V; i++)
       {
           if(!vis[i])
           {
               if(detect(i,adj,vis)) return true;
           }
       }
       return false;
    }
};