class Solution {
    unordered_map<int,vector<int>>adjlist;
    unordered_set<int> vist_cycle;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre : prerequisites)
        {
            adjlist[pre[0]].push_back(pre[1]);
        }

        for(int crs =0 ;crs< numCourses;crs++ )
        {
            if(!dfs(crs))
            {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(int crs)
    {
        if(vist_cycle.count(crs))
        {
            return false;
        }

        if(adjlist[crs].empty())
        {
            return true;
        }
        vist_cycle.insert(crs);
        for(auto c : adjlist[crs] )
        {
           if(!dfs(c))
           {
            return false;
           }
        }

        vist_cycle.erase(crs);
        adjlist[crs].empty();
        return true;
    }
};
