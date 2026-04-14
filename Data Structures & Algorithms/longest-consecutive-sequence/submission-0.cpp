class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
    unordered_set<int> s(nums.begin(), nums.end());
    int mx=0;
    for(auto num : nums )
    {
        int len=0;
        if(s.find(num -1)== s.end())
        {
            len++;
            while(s.find(num +len)!= s.end())
            {
                len++;
            }
            mx = max(len,mx);
        }
    }
    return mx;    
    }
};
