class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        unordered_set<char> ss(s.begin(), s.end());
        for(auto c :ss)
        {
            int l=0 , cnT =0; // count number of char occurance
            for(int r =0; r<s.size();r++)
            {
                if(s[r]== c){cnT ++;}
                while((r - l + 1 -cnT) > k) //number of other chars
                {
                    if(s[l]== c){cnT --;}
                    l++;

                }

                res = max(res , r-l +1);
            }
        }
        return res;
    }
};
