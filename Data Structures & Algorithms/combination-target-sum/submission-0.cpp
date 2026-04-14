class Solution {
public:
    vector<vector<int>> res;
    vector<int> num;
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<int> cur;
        num = nums;
        dfs(0,target,cur);   
        return res; 
    }

    void dfs(int i ,int targ ,vector<int>& cur)
    {
        if(targ ==0)
        {
            res.push_back(cur);
            return;
        }
        if(targ<0 || i>= num.size())
        {
            return;
        }
        cur.push_back(num[i]);
        dfs(i,targ - num[i],cur);
        cur.pop_back();
        dfs(i+1,targ,cur);
    }
};
