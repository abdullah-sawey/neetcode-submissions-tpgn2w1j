class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!= t.size())
       {
        return false;
       } 
       unordered_map<char, int> ms,mT;
       for(int i =0; i<s.size();i++)
       {
           ms[s[i]]++;
           mT[t[i]]++;
       }

       for(int i =0; i<s.size();i++)
       {
        if(ms[s[i]] != mT[s[i]])
        {
            return false;
        }
       }
       return true;
    }
};
