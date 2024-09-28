class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
    
        sort(maximumHeight.begin(), maximumHeight.end());
        
        long long totalSum = 0;
        int currentHeight = maximumHeight[n - 1];
        
        for (int i = n - 1; i >= 0; --i) {
            if (currentHeight > maximumHeight[i]) {
                currentHeight = maximumHeight[i]; 
            }
            
            if (currentHeight <= 0) {
                return -1;
            }
            
            totalSum += currentHeight; 
            currentHeight--;        
        }
        
        return totalSum;
    }
};