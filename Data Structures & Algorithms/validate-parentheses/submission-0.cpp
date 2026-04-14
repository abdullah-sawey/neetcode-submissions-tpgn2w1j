class Solution {
public:
    bool isValid(string s) {
        stack<char>ss;
     unordered_map<char,char> mp=
     {
        {')','('},
        {']','['},
        {'}','{'},
     };

     for(auto c: s)
     {
        if(mp.count(c))//close barcket
        {
            if(!ss.empty()&& ss.top()== mp[c])
            {
                ss.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            ss.push(c);
        }
     }
     return ss.empty();   
    }
};
