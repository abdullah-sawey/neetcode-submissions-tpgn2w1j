class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int>vist;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if(!dfs(0,-1))
        {
            return false;
        }

        return (vist.size() == n);
    }

    private:
    bool dfs(int node , int par )
    {
        if(vist.count(node))
        {
            return false;
        }

        vist.insert(node);
        for(auto nie : adj[node])
        {
            if(nie == par)
            {
                continue;
            }

            if(!dfs(nie ,node))
            {
                return false;
            }
        }
        return true;
    }
};
