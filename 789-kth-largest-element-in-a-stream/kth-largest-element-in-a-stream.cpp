class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    int m_k;
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for(int num:nums)add(num);
        
    }
    
    int add(int val) {
        if(minheap.size()<m_k)minheap.push(val);
        else{
            if(minheap.top()<val){
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */