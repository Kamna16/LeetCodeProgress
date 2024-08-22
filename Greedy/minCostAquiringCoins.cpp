#include<bits/stdc++.h> 
using namespace std; 

int minCost(int coin[], int n, int k) 
{ 
	sort(coin, coin + n); 

	int coins_needed = ceil(1.0 * n / 
							(k + 1)); 

	int ans = 0; 
	for (int i = 0; i <= coins_needed - 1; 
									i++) 
		ans += coin[i]; 
	
	return ans; 
} 
