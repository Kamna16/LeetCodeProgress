class Solution {
public:
    #define P pair<int,int> 
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n+1,INT_MAX);
        vector<int> d2(n+1,INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,1});
        d1[1] = 0;
        while(!pq.empty())
        {
            auto timePassed = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            // if we have reached the destination
            if(node == n && d2[n] != INT_MAX) return d2[n];
            int div = timePassed/change;
            if(div%2 == 1)// odd->red
            {
                timePassed = change*(div+1);
            }
            for(auto nbr : adj[node])
            {
                if(d1[nbr] > timePassed+time )
                {
                    d2[nbr] = d1[nbr];
                    d1[nbr] = timePassed+time;
                    pq.push({timePassed+time, nbr});
                }else if(d2[nbr] > timePassed +time && d1[nbr] != timePassed +time)
                {
                    d2[nbr] = timePassed+time;
                    pq.push({timePassed+time, nbr});
                }
            }
        }
        return -1;
    }
};