class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int>mp;
     int diff=0;

     for(int i=0; i< nums.size();i++)
     {
        mp[nums[i]]=i;
     }   
     for(int i=0; i< nums.size();i++)
     {
        diff =target - nums[i];
        if(mp.count(diff)&& mp[diff] != i)
        {
            return {i ,mp[diff]};
        }
     }

     return {};
    }
};
