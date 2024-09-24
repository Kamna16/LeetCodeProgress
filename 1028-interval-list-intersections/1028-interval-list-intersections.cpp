class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < f.size() && j < s.size()) {
            int start = max(f[i][0], s[j][0]);
            int end = min(f[i][1], s[j][1]);

            if (start <= end) {
                ans.push_back({start, end}); 
            }

            if (f[i][1] < s[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};