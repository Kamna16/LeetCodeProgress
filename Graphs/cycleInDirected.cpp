#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<bool> vis;
    bool solve(int V, vector<int> adj[], int u,vector<bool> &inRecursion)
    {
        if(vis[u]) return true;
        vis[u]=true;
        inRecursion[u]=true;
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                if(solve(V,adj,v,inRecursion)) return true;
            }else if(inRecursion[v])return true;
        }
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
       vis.resize(V, false);
       vector<bool> inRecursion(V,false);
       
       for(int i=0;i<V;i++)
       {
           if(!vis[i] && solve(V,adj,i,inRecursion)) return true;
       }
       return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}