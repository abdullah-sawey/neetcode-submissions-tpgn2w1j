class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2)
    {
        memo=vector<vector<int>>(text1.size(),vector<int>(text2.size(),-1));
        return dfs(0,0,text1,text2);
    } 
    int dfs(int i,int j,string s1, string s2)  
    {
        if((i == s1.size()) ||( j == s2.size()) )
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        if(s1[i]==s2[j]){memo[i][j]= 1+ dfs(i+1,j+1,s1,s2);}
        else
        {
            memo[i][j] =max(dfs(i+1,j,s1,s2),dfs(i,j+1,s1,s2));
        }

        return memo[i][j];
    } 
    
};
