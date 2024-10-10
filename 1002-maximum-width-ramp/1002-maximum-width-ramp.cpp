class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int max_right[n];
        max_right[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max_right[i] = max(max_right[i+1] ,arr[i]);
        }
        int i=0;
        int j=0;
        while(j<n)
        {
            while(i<j && max_right[j] < arr[i])i++;
            maxi = max(maxi, j-i);
            j++;
        }
        return maxi;
    }
};