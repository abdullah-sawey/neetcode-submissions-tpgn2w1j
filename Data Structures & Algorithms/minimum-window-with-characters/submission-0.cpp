class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){return "";}
        int res =INT_MAX ,hv=0, nd =0 ,l =0;
        string sub="";
        unordered_map<char,int> mhv, wd;
        for(int i=0; i<t.size();i++)
        {
            mhv[t[i]]++;
        }
        nd = mhv.size();
        for(int r =0;r<s.size();r++)
        {
            wd[s[r]]++;
            if(mhv.count(s[r]) && mhv[s[r]] == wd[s[r]] )
            {
                hv++;
            }

            while(hv == nd)
            {
                if(r-l+1 < res)
                {
                    res =r-l+1;
                    sub = s.substr(l,res);
                }
                wd[s[l]]--;
                if(mhv.count(s[r]) && mhv[s[l]] >wd[s[l]] )
                {
                     hv--;
                }
                l++;
            }
        }
        return sub;
    }
};
