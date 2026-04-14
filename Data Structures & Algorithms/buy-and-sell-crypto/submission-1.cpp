class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l=0 ,r=1,mx =0,pr=0;
        while(r<prices.size())
        {
            if(prices[l]<prices[r])
            {
                pr = prices[r] - prices[l];
                mx = max(pr,mx);
            }
            else
            {
                l=r;
            }
            r++;
        }
        return mx;
    }
};
