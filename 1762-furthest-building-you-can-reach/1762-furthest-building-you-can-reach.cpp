class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int count = 0;
        priority_queue<int> pq;
        int i;
        for (i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            
            if(heights[i+1] <= heights[i]) continue;
            if(diff<=bricks)
            {
                bricks-= diff; 
                pq.push(diff);
            }else if(ladders >0)
            {
                if(!pq.empty())
                {
                    int maxPast = pq.top();
                    if(maxPast>diff)
                    {
                        bricks += maxPast;
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }else break;
        }
        
        return i;
    }
};