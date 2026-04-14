class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int goal = accumulate(nums.begin(),nums.end(),0);
        if(goal %2 !=0)
        {
            return false;
        }
        goal /=2;
        vector<vector<bool>>dp(nums.size() + 1,vector<bool>(goal + 1,false));
        for(int i=0;i<=nums.size();i++)
        {
            dp[i][0]= true;
        }

        for(int i=1;i <= nums.size();i++)
        {
            for(int j=1;j <= goal;j++)
            {
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1] ]);

            }
        } 
        return dp[nums.size()][goal];
    }
};
