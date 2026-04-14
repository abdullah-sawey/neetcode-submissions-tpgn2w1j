class Solution {
public:
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }

private:
void bfs(vector<vector<char>>& grid,int r, int c)
{
    queue<pair<int,int>>q;
    grid[r][c]='0';
    q.push({r,c});
    while(!q.empty())
    {
        auto curr =q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
           r= curr.first + dir[i][0];
           c= curr.second + dir[i][1]; 
           if((r>=0)&&(c>=0)&&(r<grid.size())&&(c<grid[0].size())&&(grid[r][c]=='1') )
           {
            q.push({r,c});
            grid[r][c]='0';
           }
        }
    }
}
};
