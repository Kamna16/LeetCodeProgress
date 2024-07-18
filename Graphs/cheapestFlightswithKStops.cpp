#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; // storing src--> dest,cost
        vector<int> minCost(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            int src = flights[i][0];
            int dest = flights[i][1];
            int cost = flights[i][2];
            adj[src].push_back({dest,cost});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        minCost[src] = 0;
        int steps=0;
        while(!q.empty() && steps<=k)
        {
            int N = q.size();
            while(N--)
            {
                pair<int,int> curr = q.front();
                int u= curr.first;
                int cost= curr.second;

                q.pop();

                for(auto p: adj[u])
                {
                    int v = p.first;
                    int c = p.second;

                    if(minCost[v] > cost + c)
                    {
                        minCost[v] = cost +c;
                        q.push({v,cost+c});
                    }
                }
            }
            steps++;
        }
        if(minCost[dst] == INT_MAX) return -1;
        return minCost[dst];
    }
};