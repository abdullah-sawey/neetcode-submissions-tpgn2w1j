class Solution {
public:
    vector<string> s;
    int nn;
    vector<string> generateParenthesis(int n) 
    {
        string ss;
        nn=n;
        dfs(0,0,ss);
        return s;
    }

    void dfs(int o, int c, string ss)
    {
        if(ss.size()== 2*nn)
        {
            s.push_back(ss);
            return;
        }
        if(o<nn)
        {
            ss+='(';
            dfs(o+1,c,ss);
            ss.pop_back();
        }
        if(c<o)
        {
            ss+=')';
            dfs(o,c+1,ss);
            ss.pop_back();
        }
    }
};
