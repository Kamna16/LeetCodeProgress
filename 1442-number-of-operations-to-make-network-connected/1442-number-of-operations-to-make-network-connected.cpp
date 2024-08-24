class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int x)
    {
        if(parent[x] == x) return x;

        return parent[x] = findParent(parent[x]);
    }
    void Union(int x, int y)
    {
        int xParent = findParent(x);
        int yParent = findParent(y);
        if(xParent == yParent) return;

        if(rank[xParent] > rank[yParent])
        {
            parent[yParent] = xParent; 
        }else if(rank[yParent] > rank[xParent])
        {
            parent[xParent] = yParent; 
        }else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        int components = n;
        for(auto vec : connections)
        {
            int u = vec[0];
            int v = vec[1];
            if(findParent(u) != findParent(v))
            {
                Union(u,v);
                components--;
            }
        }
        return components-1;
    }
};