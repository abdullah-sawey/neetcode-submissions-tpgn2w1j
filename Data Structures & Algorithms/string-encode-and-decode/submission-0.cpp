class Solution {
public:

    string encode(vector<string>& strs)
    {
        string s;
        for(auto sr: strs)
        {
            s+= to_string(sr.size()) + '#'+sr;
        }
        return s;

    }

    vector<string> decode(string s) 
    {
        vector<string> res;
        int i=0,j=0,len=0;
        while(i<s.size())
        {
            while(s[j]!='#')
            {
                j++;
            }
            len = stoi(s.substr(i,j-i));
            i= j+1;
            j= i+len;
            res.push_back(s.substr(i,len));
            i=j;
        }
        return res;

    }
};
