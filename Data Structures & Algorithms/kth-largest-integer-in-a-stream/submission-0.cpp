class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
    {
    k_=k;
    for (int i :nums)
    {
        minheap.push(i);
        if(minheap.size()>k)
        {
            minheap.pop();
        }
    }

    }
    
    int add(int val) 
    {
        minheap.push(val);   
        if(minheap.size()>k_)
        {
            minheap.pop();
        }
        return minheap.top();

    }
private:
int k_;
priority_queue<int , vector<int> , greater<int> > minheap;
};
