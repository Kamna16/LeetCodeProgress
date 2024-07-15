#include <bits/stdc++.h>
using namespace std;

// sorting method
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long mini = INT_MAX;
        for(int i=0;i+m-1<n;i++)
        {
            long long sub = a[i+m-1]-a[i];
            mini = min(mini, sub);
        }
        return mini;
    }   
};

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}