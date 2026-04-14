class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx =0,l=0,r=heights.size()-1;
        while(l<r)
        {
            int cur = min(heights[l],heights[r]) * (r -l);
            mx = max(cur,mx);
            if(heights[l]<heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return mx;

    }
};
