class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first > arr[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top().second;
            st.push({arr[i], i});
        }

        while (!st.empty()) st.pop(); 

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            right[i] = st.empty() ? n : st.top().second;
            st.push({arr[i], i});
        }

        long long result = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }

        return result;
    }
};