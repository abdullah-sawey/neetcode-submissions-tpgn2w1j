class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string , vector<string>> res;
        vector<vector<string>> ans;
        vector<int> counT(26 , 0);
        for (const auto sTr : strs)
        {
            vector<int> counT(26 , 0);
            for(auto c : sTr)
            {
                counT[c -'a']++;
            }

            string key = to_string(counT[0]);
            for(int i=1;i<26;i++)
            {
                key+= '#' + to_string(counT[i]);
            }
            res[key].push_back(sTr);
        }
        for(auto pair : res)
        {
            ans.push_back(pair.second);
        }

        return ans;
    }
};