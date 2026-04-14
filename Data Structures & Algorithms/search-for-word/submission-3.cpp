class Solution {
public:
    vector<vector<char>> bd;
    string wd;
    int row ,col;
    set<pair<int,int>> ph;
    bool exist(vector<vector<char>>& board, string word)
    {
        bd = board;
        wd = word;
        row = board.size();
        col = board[0].size();
        for(int i =0; i<row;i++)
        {
            for(int j =0; j<col;j++)
            {
                if(dfs(i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int r ,int c, int i)
    {
        if(i == wd.size())
        {
            return true;
        }
        
        if( r>=row || c>= col || r<0 || c<0 || bd[r][c]!=wd[i]
         || ph.count({r,c}))
        {
            return false ;
        }
        ph.insert({r,c});
        bool res = dfs(r+1,c,i+1)||
                   dfs(r-1,c,i+1)||
                   dfs(r,c+1,i+1)||
                   dfs(r,c-1,i+1);
        ph.erase({r,c});
        return res;
    }
};
