class Solution {
public:
#define P pair<int,int>

    void floydWarshall(int n, vector<vector<int>>& SPM) {
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                }
            }
        }
    }

    int findResultCity(int n, vector<vector<int>>& SPM, int D) {
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for(int i = 0; i < n; i++) {
            int countReach = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && SPM[i][j] <= D) {
                    countReach++;
                }
            }
            if(countReach <= leastReachCount) {
                leastReachCount = countReach;
                resultCity = i;
            }
        }
        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) {
            SPM[i][i] = 0;
        }

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        floydWarshall(n, SPM);

        return findResultCity(n, SPM, distanceThreshold);
    }
};
