class Solution {
public:
    vector<vector<int>> dp;
    int lastStoneWeightII(vector<int>& stones) 
    {
        int all = accumulate(stones.begin(),stones.end(),0);
        int Targ = (all+1)/2;
        dp = vector<vector<int>>(stones.size()+1,vector<int>(Targ +1,-1));
        return dfs(0,0,stones,all,Targ) ; 
    }

    int dfs(int i , int sum ,vector<int>& stones , int all , int Targ)
    {
        if((i == stones.size()) || (sum>= Targ))
        {
            return abs(sum -(all - sum) );
        }
        if(dp[i][sum]!=-1){ return dp[i][sum];}

        dp[i][sum]= min(dfs(i+1,sum,stones,all,Targ) ,
        dfs(i+1,sum + stones[i],stones,all,Targ));
        return dp[i][sum];
    }
};