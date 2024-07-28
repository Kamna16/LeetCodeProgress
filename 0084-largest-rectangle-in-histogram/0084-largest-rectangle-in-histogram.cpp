class Solution {
public:
    vector<int> PrevSmaller(vector<int>& arr,int n)
    {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            int elem = st.empty() ? -1 : st.top();
            ans.push_back(elem);
            st.push(i);
        }
        return ans;
    }
    vector<int> NextSmaller(vector<int>& arr,int n)
    {
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            int elem = st.empty() ? n : st.top();
            ans.push_back(elem);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int n = heights.size();
        vector<int> PS = PrevSmaller(heights,n);
        vector<int> NS = NextSmaller(heights,n);

        for(int i=0;i<n;i++)
        {
            int area = (NS[i]-PS[i]-1) * heights[i];
            maxArea= max(maxArea,area);
        }
        return maxArea;
    }
};