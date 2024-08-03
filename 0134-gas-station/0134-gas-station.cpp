class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        int n = gas.size();
        int fuel =0;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                ans = i+1;
                fuel = 0;
            }
        }
        return ans;

    }
};