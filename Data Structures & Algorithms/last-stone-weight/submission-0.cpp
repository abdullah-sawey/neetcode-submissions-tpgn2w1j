class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int>maxheap;
        for(int stone : stones)
        {
        maxheap.push(stone); 
        }
        while(maxheap.size()>1)
        {
            int first = maxheap.top();
            maxheap.pop();
            int sec = maxheap.top();
            maxheap.pop();
            if((first -sec) >0)
            {
                maxheap.push(first - sec);
            }
        }
        return (!maxheap.empty()) ? maxheap.top() : 0;
    }
};
