class Solution {
public:
    vector<vector<int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int Rows = heights.size(), Cols =heights[0].size();
        vector<vector<bool>> oc1(Rows,vector<bool>(Cols,false));
        vector<vector<bool>> oc2(Rows,vector<bool>(Cols,false));
        vector<vector<int>>res;

        for(int i=0; i<Rows;i++)
        {
            dfs(i,0,oc1,heights);
            dfs(i,Cols-1,oc2,heights);
        }

        for(int i=0; i<Cols;i++)
        {
            dfs(0,i,oc1,heights);
            dfs(Rows-1,i,oc2,heights);
        }

        for(int i=0; i<Rows;i++)
        {
            for(int j=0; j<Cols;j++)
            {
                if(oc1[i][j]&&oc2[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
    private:
    void dfs(int r, int c , vector<vector<bool>>& oc,vector<vector<int>>& heights)
    {
        oc[r][c]=true;
        for(auto i: dir)
        {
            int nr = r+i[0] , nc = c+i[1];
            if((nr>=0 && nr<heights.size())&&(nc>=0 && nc<heights[0].size())
            &&(heights[nr][nc]>=heights[r][c]&&!oc[nr][nc]) )
            {
                dfs(nr,nc,oc,heights);
            }

        }



    }


};
