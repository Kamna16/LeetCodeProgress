class Solution {
public:
    int n;
    int count;
    vector<bool> vis;
    void dfs(int idx, vector<vector<int>>& stones)
    {
        vis[idx] = true;

        for(int i=0;i<n;i++)
        {
            if(!vis[i] && (stones[idx][0] == stones[i][0] ||stones[idx][1] == stones[i][1]))
            {
                dfs(i,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        int groups = 0;
        vis.resize(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,stones);
                groups++;
            }
        }
        return n-groups;;
    }
};