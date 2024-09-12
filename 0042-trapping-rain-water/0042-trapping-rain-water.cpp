class Solution {
public:
    vector<int> calcLeft(vector<int>& height)
    {
        vector<int> ans(height.size());
        ans[0] = height[0];
        for(int i=1;i<height.size();i++)
        {
            ans[i] = max(ans[i-1], height[i]);
        }
        return ans;
    }
    vector<int> calcRight(vector<int>& height)
    {
        int n = height.size();
        vector<int> ans(n);
        ans[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = max(ans[i+1], height[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int count =0;
        int n = height.size();
        vector<int> leftMax = calcLeft(height);
        vector<int> rightMax = calcRight(height);
        for(int i=0;i<n;i++)
        {
            count += min(leftMax[i], rightMax[i]) - height[i];
        }
        return count;
    }
};