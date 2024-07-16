#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int product = 1;
        int zeroCount = 0;

        for(int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                product *= nums[i];
            } else {
                zeroCount++;
            }
        }

        vector<long long int> ans(n, 0); 

        if (zeroCount > 1) {
            return ans; 
        }

        for(int i = 0; i < n; i++) {
            if (zeroCount == 0) {
                ans[i] = product / nums[i];
            } else if (zeroCount == 1 && nums[i] == 0) {
                ans[i] = product;
            }
        }

        return ans;
    }
};

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}