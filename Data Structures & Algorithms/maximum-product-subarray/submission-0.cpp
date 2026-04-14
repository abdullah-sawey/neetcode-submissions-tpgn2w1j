class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int res =nums[0],tmp=0;
        int curmx=1,curmin=1;
        for(int i=0; i<nums.size();i++)
        {
            tmp =curmx * nums[i];
            curmx =max(max(curmx * nums[i],curmin * nums[i]),nums[i]);
            curmin =min(min(tmp,curmin * nums[i]),nums[i]);
            res= max(curmx,res);

        }
        return res;
    }
};
