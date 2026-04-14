class Solution {

public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total_sum = 0;

        for (int num : nums) {

            total_sum += num;

        }

        // If target is out of possible range, return 0

        if (abs(target) > total_sum) {

            return 0;

        }

        // DP table: dp[i][j] = number of ways to achieve sum j 

        // after considering first i elements

        // j ranges from -total_sum to total_sum, so we shift by total_sum

        int offset = total_sum;

        int size = 2 * total_sum + 1;

        vector<vector<int>> dp(n + 1, vector<int>(size, 0));

        // Base case: 0 elements, sum = 0

        dp[0][0 + offset] = 1;

        // Fill DP table using i-1 approach

        for (int i = 1; i <= n; i++) {

            for (int j = -total_sum; j <= total_sum; j++) 
            {

                int current_j = j + offset;

                // Only process if the current state is reachable

                    // If we add nums[i-1]

                    int add_index = current_j + nums[i-1];
                        dp[i][add_index] += dp[i-1][current_j];

                    

                    // If we subtract nums[i-1]

                    int sub_index = current_j - nums[i-1];
                        dp[i][sub_index] += dp[i-1][current_j];

                    

            }


        }

        return dp[n][target + offset];

    }

};
 