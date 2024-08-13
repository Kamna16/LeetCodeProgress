class Solution {
public:
    int cnt = 0;

    void merge(int p, int q, int r, vector<int>& arr) {
        int n = q - p + 1;
        int m = r - q;
        vector<int> arr1(n);
        vector<int> arr2(m);
        
        int j = 0;
        for (int i = p; i <= q; i++) {
            arr1[j] = arr[i];
            j++;
        }
        j = 0;
        for (int i = q + 1; i <= r; i++) {
            arr2[j] = arr[i];
            j++;
        }
        
        // Count reverse pairs
        int i = 0;
        j = 0;
        while (i < n) {
            while (j < m && (long long)arr1[i] > 2 * (long long)arr2[j]) {
                j++;
            }
            cnt += j;
            i++;
        }
        
        // Merge arrays
        i = 0, j = 0;
        int k = p;
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                arr[k] = arr1[i];
                i++;
            } else {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < n) {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while (j < m) {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    void sortArray(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        sortArray(arr, l, mid);
        sortArray(arr, mid + 1, r);
        merge(l, mid, r, arr);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        cnt = 0;
        sortArray(nums, 0, n - 1);
        return cnt;
    }
};
