class Solution {

public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total_sum = 0;

        for (int num : nums) {

            total_sum += abs(num);

        }

        // If target is out of possible range, return 0

        if (abs(target) > total_sum) {

            return 0;

        }

        // DP table: dp[i][j] = number of ways to achieve sum j after considering first i elements

        // j ranges from -total_sum to total_sum, so we shift by total_sum for array indexing

        int offset = total_sum;

        vector<vector<int>> dp(n + 1, vector<int>(2 * total_sum + 1, 0));
        // Base case: 0 elements, sum = 0 (1 way)
        dp[0][0 + offset] = 1;
        // Fill DP table using the exact recurrence relation
        for (int i = 1; i <= n; i++) {
            for (int j = -total_sum; j <= total_sum; j++) {
                int current_j = j + offset; // Shifted index for array access
                // Initialize with 0
                // Option 1: Add +nums[i-1] to previous sum
                int prev_sum_add = j - nums[i - 1];
                if (prev_sum_add >= -total_sum && prev_sum_add <= total_sum) {
                    dp[i][current_j] += dp[i - 1][prev_sum_add + offset];
                }
                // Option 2: Add -nums[i-1] to previous sum  
                int prev_sum_subtract = j + nums[i - 1];
                if (prev_sum_subtract >= -total_sum && prev_sum_subtract <= total_sum) {

                    dp[i][current_j] += dp[i - 1][prev_sum_subtract + offset];

                }
            }
        }

        return dp[n][target + offset];

    }

};
 