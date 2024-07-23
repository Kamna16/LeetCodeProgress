class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int time =0;
        int fresh =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if(fresh ==0) return 0;
        //bfs
        while(!q.empty())
        {
            int Qsize = q.size();
            int temp =0;
            while(Qsize !=0)
            {
                pair<int,int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                int ax[4] = {1,-1,0,0};
                int ay[4] = {0,0,1,-1};

                for(int i=0;i<4;i++)
                {
                    int delx = ax[i]+x;
                    int dely = ay[i]+y;

                    if(delx>=0 && delx<n && dely>=0 && dely<m && grid[delx][dely]==1)
                    {
                        temp++;
                        grid[delx][dely] =2;
                        q.push({delx,dely});
                    }
                }

                Qsize--;
            }
            if(temp!=0) time++;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    time =-1;
                }
            }
        }

        return time;
    }
};