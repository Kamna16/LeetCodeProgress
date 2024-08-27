class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double> prob(n, 0);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            double pro = succProb[i];
            adj[u].push_back({v,pro});
            adj[v].push_back({u,pro});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        prob[start_node] = 1.0;
        while(!pq.empty())
        {
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &n : adj[node])
            {
                int adjNode = n.first;
                double probability = n.second;
                if(p*probability > prob[adjNode])
                {
                    prob[adjNode] = p*probability;
                    pq.push({prob[adjNode],adjNode});
                }
            }
        }
        return prob[end_node];
    }
};