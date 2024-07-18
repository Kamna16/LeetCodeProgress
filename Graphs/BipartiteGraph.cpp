#include<bits/stdc++.h>
using namespace std;

// using 2 colors --> 0,1
class Solution {
public:
    vector<int> visited;
    bool Bipartite = true;
    void dfs(int u,vector<int>adj[], int color)
    {
        if(visited[u] != -1) return;
        visited[u] = color;
        for(int v : adj[u])
        {
            if(visited[v] == -1) dfs(v,adj,1-color);
            else if(visited[v] == color)
            {
                Bipartite = false;
                return;
            }
        }
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int n = V;
        visited.resize(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                dfs(i, adj, 1);
            }
        }
        
        return Bipartite;
	}

};
