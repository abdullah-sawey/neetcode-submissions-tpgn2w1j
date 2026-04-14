class Solution {
public:
    vector<int> pr;
    vector<vector<int>>dp;
    int maxProfit(vector<int>& prices)
    {
        pr = prices;
        dp = vector<vector<int>>(2,vector<int>(prices.size(),-1));
        return dfs(true ,0);

    }

    int dfs(bool buy,int i)
    {
        if(i>=pr.size())
        {
            return 0;
        }
        if(dp[buy][i]!=-1)
        {
            return dp[buy][i];
        }
        int col =0 ,by =0 ,sl=0;
        if(buy)
        {
            col = dfs(buy,i+1);
            by = - pr[i] +dfs(!buy,i+1);
            dp[buy][i] = max(col, by);
            return dp[buy][i];
        }
        else
        {
            col = dfs(buy,i+1);
            sl  =  pr[i] +dfs(!buy,i+2);
            dp[buy][i] = max(col,sl) ;
            return dp[buy][i];
        }
    }
};
