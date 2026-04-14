class Solution {

public:

    int lastStoneWeightII(vector<int>& stones) {

        int total = accumulate(stones.begin(), stones.end(), 0);

        int target = total / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int stone : stones) {

            for (int t = target; t >= stone; t--) {

                dp[t] = dp[t] || dp[t - stone];

            }

        }

        for (int t = target; t >= 0; t--) {

            if (dp[t]) return total - 2 * t;

        }

        return total;

    }

};
 