class Solution {
public:
   int coinChange(vector<int>& coins, int amount) {
       if (amount == 0) return 0;
       int res = dfs(0, amount, coins, amount);
       return (res == 1e9) ? -1 : res;
   }
   int dfs(int i, int sum, vector<int>& coins, int amount) {
       // Base cases
       if (sum == 0) return 0;
       if (i >= coins.size() ) return 1e9;
       int take = 1e9, skip = 1e9;
       // Take current coin
       if (sum - coins[i] >=0) {
           take = 1 + dfs(i, sum - coins[i], coins, amount);
       }
       // Skip current coin
       skip = dfs(i + 1, sum, coins, amount);
       return min(take, skip);
   }
};