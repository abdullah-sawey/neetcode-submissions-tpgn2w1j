class Solution {
public:
    vector<vector<int>> dp;
    int lastStoneWeightII(vector<int>& stones) 
    {
        int all = accumulate(stones.begin(),stones.end(),0);
        int Targ = (all+1)/2;
        dp = vector<vector<int>>(stones.size()+1,vector<int>(Targ +1,0));
        for(int i=1;i<=stones.size();i++)
        {
            for(int j=0;j<=Targ;j++)
            {
                if(stones[i-1]<=j)
                {
                    dp[i][j]= max(dp[i-1][j],dp[i-1][j- stones[i-1]]+stones[i-1]);
                }
                else{dp[i][j]=dp[i-1][j];}
            }
        }
        return abs (dp[stones.size()][Targ] - (all- dp[stones.size()][Targ]));
    }
};