//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st)
	{
	    visited[u] = true;
	    
	    for(int & v: adj[u])
	    {
	        if(!visited[v])
	        {
	            dfs(v,adj,visited,st);
	        }
	    }
	    st.push(u);
	}
	void dfsTraversal(int u, vector<vector<int>>& adj, vector<bool> &visited)
	{
	    visited[u] = true;
	    
	    for(int & v: adj[u])
	    {
	        if(!visited[v])
	        {
	            dfsTraversal(v,adj,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> visited(V);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }
        vector<vector<int>> reversedAdj(V);
        for(int u=0;u<V;u++)
        {
            for(int &v : adj[u])
            {
                reversedAdj[v].push_back(u);
            }
        }
        
        int count =0;
        visited = vector<bool>(V,false);
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfsTraversal(node,reversedAdj,visited);
                count++;
            }
            
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends