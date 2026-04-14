class Solution {
public:
    vector<vector<bool>> dp;
    int lastStoneWeightII(vector<int>& stones) 
    {
        int all = accumulate(stones.begin(),stones.end(),0);
        int Targ = (all+1)/2;
        dp = vector<vector<bool>>(stones.size()+1,vector<bool>(Targ +1,false));
        for(int i=0;i<stones.size();i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=stones.size();i++)
        {
            for(int j=0;j<=Targ;j++)
            {
                if(stones[i-1]<=j)
                {
                    dp[i][j]= dp[i-1][j]|| dp[i-1][j- stones[i-1]];
                }
                else{dp[i][j]=dp[i-1][j];}
            }
        }
        for(int j=Targ;j>0;j--)
        {
            if(dp[stones.size()][j]){return abs(j-(all-j));}
        }
    return all;
    }
};