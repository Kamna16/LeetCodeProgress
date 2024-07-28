#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	 vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unionfind(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
	int krushkals(vector<vector<int>> &vec)
	{
	    int sum = 0;
	    for(auto temp : vec)
	    {
	        int u= temp[0];
	        int v= temp[1];
	        int wt= temp[2];
	        
	        int p_u = find(u);
	        int p_v = find(v);
	        if(parent[p_u] != parent[p_v])
	        {
	            unionfind(u,v);
	            sum += wt;
	        }
	    }
	    return sum;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++)
        {
            parent[i] = i;
        }

        vector<vector<int>> vec;
        for(int u=0;u<V;u++)
        {
            for(auto temp : adj[u]){
                int v = temp[0];
                int wt = temp[1];
                vec.push_back({u,v,wt});
            }
        }
        auto comp = [&](vector<int> &v1, vector<int> &v2){
            return v1[2]<v2[2];
        };
        sort(vec.begin(),vec.end(),comp);
        
        return krushkals(vec);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

