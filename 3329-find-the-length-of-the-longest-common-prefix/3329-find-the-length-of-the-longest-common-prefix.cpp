class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int i=0;i<arr1.size();i++)
        {
            int curr = arr1[i];
            while(!st.count(curr) && curr > 0)
            {
                st.insert(curr);
                curr = curr/10;
            }
        }
        int maxi = 0;
        for(int i=0;i<arr2.size();i++)
        {
            int curr = arr2[i];
            while(!st.count(curr) && curr > 0)
            {
                curr = curr/10;
            }
            if(curr>0)
            {
                maxi = max(maxi,static_cast<int>(log10(curr)+1));
            }
        }
        return maxi;
    }
};