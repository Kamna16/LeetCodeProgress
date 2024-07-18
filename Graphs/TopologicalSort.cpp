#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	stack<int> st;
	vector<bool> visited;
	void dfs(vector<int> adj[],int u)
	{
	    visited[u] = true;
	    for(int & v : adj[u])
	    {
	        if(!visited[v]) dfs(adj,v);
	    }
	    st.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    visited.resize(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(adj,i);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        int node = st.top();
	        ans.push_back(node);
	        st.pop();
	    }
	    return ans;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}