class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> inMins(n);
        for(int i=0;i<n;i++)
        {
            string h = timePoints[i].substr(0,2);
            string m = timePoints[i].substr(3);

            int H = stoi(h);
            int M = stoi(m);

            inMins[i] = H*60 + M;
        }
        int diff = INT_MAX;
        sort(inMins.begin(),inMins.end());
        for(int i=1;i<n;i++)
        {
            diff = min(diff, inMins[i]-inMins[i-1]);
        }
        int calc = (60*24 - inMins[n-1]) + inMins[0];
        if(calc < diff) return calc;
        return diff;
    }
};