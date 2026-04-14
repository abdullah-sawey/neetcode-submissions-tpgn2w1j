class Solution {
public:
    vector<vector<int>> mx;
    int col , row;
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int res =0;
        mx= matrix; 
        row = matrix.size();
        col = matrix[0].size();
        for(int i=0; i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res = max(res , dfs(i,j,INT_MIN));
            }
        } 
        return res;

    }

    int dfs(int r , int c, int prev)
    {
        if(r>=row || r<0 || c>= col || mx[r][c]<= prev)
        {
            return 0;
        }
        int d0 = 1+dfs(r +1,c,mx[r][c]);
        int d1 = 1+dfs(r,c+1,mx[r][c]);
        int d2 = 1+dfs(r -1,c,mx[r][c]);
        int d3 = 1+dfs(r,c-1,mx[r][c]);
        d0 = max(d0,d1);
        d3 = max(d3,d2);
        return max(d0,d3);

    }

};
