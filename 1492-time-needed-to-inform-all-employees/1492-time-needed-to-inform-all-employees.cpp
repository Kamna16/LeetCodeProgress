class Solution {
public:
    int maxTime =0;
    void bfs(unordered_map<int,vector<int>> &adj,int headID, vector<int>& informTime)
    {
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty())
        {
            pair<int,int> temp = q.front();
            int currEmp = temp.first;
            int currTime = temp.second;
            maxTime = max(maxTime,currTime);
            int size = q.size();
            q.pop();
            for(auto emp : adj[currEmp])
            {
                q.push({emp, currTime+informTime[currEmp]});
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<manager.size();i++)
        {
            int employee = i;
            int Manager = manager[i];
            if(Manager != -1)
            {
                adj[Manager].push_back(employee);
            }
        }
        bfs(adj,headID,informTime);
        return maxTime;
    }
};