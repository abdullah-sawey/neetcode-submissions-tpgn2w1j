class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {   
        int offset = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size()+1,vector<int>((offset*2)+1,0 ));
        int cj =0;
        dp[0][0+offset]=1;
        
        for(int i =1; i<=nums.size();i++)
        {
            for(int j=-offset;j<=offset;j++)
            {
                cj =j +offset;
                if(cj - nums[i-1] + offset >=0)
                {
                    dp[i][cj]+= dp[i-1][cj - nums[i-1]];
                }
                if(cj + nums[i-1]  <= 2*offset)
                {
                    dp[i][cj]+= dp[i-1][cj + nums[i-1]];
                }
                
            }
        } 
        return dp[nums.size()][target+offset] ; //not if target not between the -j to +j so the answer is zero
    }
};
