class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount)
    {   int b1 = 1e9,b2 =1e9;
        int res= dfs(0,0,coins ,amount,b1,b2);
        if(amount ==0){return 0;}
        if((amount !=0) &&(res==1e9) ){return -1;}
        return res;

    }

    int dfs(int i ,int sum ,vector<int>& coins, int amount,int b1,int b2)
    {
        if((sum == amount) ) 
        {
            return 0;
        }
        if(sum + coins[i]<=amount)
        {   
            b1 = min(b1, 1 + dfs(i,sum + coins[i],coins ,amount,b1,b2));
        }
        if(i+1<coins.size())
        {
            b2 = min(b2,dfs(i+1,sum,coins ,amount,b1,b2));
        }
        return min(b1,b2);
    }
};
