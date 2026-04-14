class Solution {
public:
    vector<int> nm;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums)
    {
        nm = nums;
        vector<int> cur;
        dfs(0,cur);
        return res;    
    }
    void dfs(int i , vector<int>& cur)
    {
        if(i==nm.size())
        {
            res.push_back(cur);
            return ;
        }

        cur.push_back(nm[i]);
        dfs(i+1,cur);
        cur.pop_back();
        dfs(i+1,cur);

    }
};
