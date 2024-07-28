#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=1;i<=V-1;i++)
        {
            for(auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v])
                {
                    dist[v] = dist[u]+wt;
                }
            }
        }
        for(auto edge : edges)
        {
            int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 1e8 && dist[u]+wt < dist[v])
                {
                    return {-1};
                }
        }
            return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
