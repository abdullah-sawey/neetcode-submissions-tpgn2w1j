class Solution {
public:
    vector<vector<int>> res;
    vector<int> nm;
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool>pk(nums.size(),0);
        vector<int> cur;
        nm = nums;
        dfs(pk,cur);
        return res;    
    }

void dfs(vector<bool>&pk,vector<int>&cur)
{
    if(cur.size() == nm.size())
    {
        res.push_back(cur);
        return ;
    }
    for(int i=0; i<nm.size();i++)
    {
        if(!pk[i])
        {
            pk[i]= true;
            cur.push_back(nm[i]);
            dfs(pk,cur);
            pk[i]= false;
            cur.pop_back();
        }
    }
}
};