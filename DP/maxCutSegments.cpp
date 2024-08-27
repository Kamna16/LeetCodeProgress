//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    vector<int> dp;
    int solve(int n, int x, int y,int z)
    {
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n] != -1) return dp[n];
        int a = 1+solve(n-x,x,y,z);
        int b = 1+solve(n-y,x,y,z);
        int c = 1+solve(n-z,x,y,z);
        
        return dp[n] = max({a,b,c});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        dp.resize(n+1,-1);
        int ans = solve(n,x,y,z);
        if(ans < 0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends