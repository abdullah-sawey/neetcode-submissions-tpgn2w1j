class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
     unordered_set<char> ss;
     int l = 0 , r = 1,ls=0;
     if(s.empty()||s.size() ==1)
     {
        return s.size();
     }
     ss.insert(s[l]);
     while(r < s.size())
     {
        while(ss.find(s[r])!= ss.end())
        {   
            ls=max(ls,r-l);
            ss.erase(s[l]);
            l++;
        }

        ss.insert(s[r]);
        r++;

     }
     return max(ls,(int)ss.size());
    }
};
