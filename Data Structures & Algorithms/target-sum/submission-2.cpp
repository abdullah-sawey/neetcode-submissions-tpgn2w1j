class Solution {
public:
   int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       int total_sum = 0;
       for (int num : nums) {
           total_sum += num;
       }
       if (abs(target) > total_sum) {
           return 0;
       }
       int offset = total_sum;
       int size = 2 * total_sum + 1;
       vector<vector<int>> dp(n + 1, vector<int>(size, 0));
       dp[0][0 + offset] = 1;
       for (int i = 1; i <= n; i++) {
           for (int j = -total_sum; j <= total_sum; j++) {
               int current_j = j + offset;
               // Only process if previous state is reachable
               if (dp[i-1][current_j] > 0) {
                   // Add nums[i-1]
                   int add_index = current_j + nums[i-1];
                   if (add_index >= 0 && add_index < size) {
                       dp[i][add_index] += dp[i-1][current_j];
                   }
                   // Subtract nums[i-1]
                   int sub_index = current_j - nums[i-1];
                   if (sub_index >= 0 && sub_index < size) {
                       dp[i][sub_index] += dp[i-1][current_j];
                   }
               }
           }
       }
       return dp[n][target + offset];
   }
};