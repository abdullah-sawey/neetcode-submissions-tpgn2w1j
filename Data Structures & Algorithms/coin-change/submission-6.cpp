class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount)
    {   
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount +1,0));
        if(amount == 0)
        {
            return 0;
        }
        for(int j = 0; j<=amount;j++)
        {
            dp[0][j]=1e9;
        }
        for(int i=1;i<=coins.size();i++)
        {
            for(int j = 1; j<=amount;j++)
            {
                int take = 1e9, skip = 1e9;
                if(j - coins[i-1]>=0)
                {
                    take = 1+ dp[i][j - coins[i-1]];
                }
                skip = dp[i-1][j];

                dp[i][j]= min(take,skip);
            }
        }
        return dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount];
    }
};
