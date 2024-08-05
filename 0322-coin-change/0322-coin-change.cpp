class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       if(amount<1) return 0;
       vector<int> dp(amount + 1, amount + 1);
       dp[0] = 0;

       for(int i=1;i<=amount;i++)
       {
          dp[i] = INT_MAX;

          for(int coin : coins)
          {
            if(coin <= i && dp[i-coin] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
          }
       }
       if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};