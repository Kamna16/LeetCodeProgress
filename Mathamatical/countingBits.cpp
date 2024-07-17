#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            if(i%2==0) ans[i]=ans[i/2];
            else ans[i]=ans[i/2]+1;
        }
        return ans;
    }
};