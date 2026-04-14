class Solution {
public:
    vector<int> pr;
    int maxProfit(vector<int>& prices)
    {
        pr = prices;
        return dfs(true ,0);

    }

    int dfs(bool buy,int i)
    {
        if(i>=pr.size())
        {
            return 0;
        }
        int col =0 ,by =0 ,sl=0;
        if(buy)
        {
            col = dfs(buy,i+1);
            by = dfs(!buy,i+1) - pr[i];
            return max(col, by);
        }
        else
        {
            col = dfs(buy,i+1);
            sl  = dfs(!buy,i+2) +pr[i];
            return max(col,sl);
        }
    }
};
