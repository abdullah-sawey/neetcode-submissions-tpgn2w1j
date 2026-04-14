class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     vector<int> res;
     priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> > minheap;
     for(auto i : nums)
     {
        mp[i]++;
     }
     for(auto pair : mp)
     {
        minheap.push({pair.second,pair.first});
        if(minheap.size()>k)
        {
            minheap.pop();
        }
     }
     for(int i=0; i<k;i++)
     {
        res.push_back(minheap.top().second);
        minheap.pop();
     } 
     return res;  
    }
};
