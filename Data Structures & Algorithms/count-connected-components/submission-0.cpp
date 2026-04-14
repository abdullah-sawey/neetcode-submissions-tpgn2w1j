class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vist;
    int res =0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n;i++)
        {
            if(vist.size()==n )
            {
                break;
            }
            else if(vist.count(i))
            {
                continue;
            }
            dfs(i);
            res++;
        }
        return res;
    }
    private:
    void dfs(int node)
    {
        if(vist.count(node))
        {
            return;
        }
        vist.insert(node);
        for(int nie : adj[node])
        {
            dfs(nie);
        }
    }
};
