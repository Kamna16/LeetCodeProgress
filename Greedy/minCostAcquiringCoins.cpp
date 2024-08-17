#include<bits/stdc++.h> 
using namespace std; 

// Converts coin[] to prefix sum array 
void preprocess(int coin[], int n) 
{ 
	// sort the coins value 
	sort(coin, coin + n); 

	// Maintain prefix sum array 
	for (int i = 1; i <= n - 1; i++) 
		coin[i] += coin[i - 1]; 
} 

// Function to calculate min 
// cost when we can get k extra 
// coins after paying cost of one. 
int minCost(int coin[], int n, int k) 
{ 
	// calculate no. of coins needed 
	int coins_needed = ceil(1.0 * n / (k + 1)); 

	// return sum of from prefix array 
	return coin[coins_needed - 1]; 
} 
 
int main() 
{ 
	int coin[] = {8, 5, 3, 10, 
				2, 1, 15, 25}; 
	int n = sizeof(coin) / sizeof(coin[0]); 
	preprocess(coin, n); 
	int k = 3; 
	cout << minCost(coin, n, k) << endl; 
	k = 7; 
	cout << minCost(coin, n, k) << endl; 
	return 0; 
} 
