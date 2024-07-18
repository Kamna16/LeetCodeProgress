#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        sort(a, a+n);
        sort(b, b+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]+b[n-1-i]< k) return false;   
        }
        return true;
    }
};
