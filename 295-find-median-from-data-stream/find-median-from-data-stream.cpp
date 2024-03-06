class MedianFinder {
public:
    double median = 0;
    priority_queue<int>leftmax;
    priority_queue<int,vector<int>,greater<int>>rightmin;
    MedianFinder() {}
    void addNum(int num) {
        if(leftmax.empty() || leftmax.top()>=num){
            leftmax.push(num);
        }
        else{
            rightmin.push(num);
        }
        //balancing
        if(leftmax.size()>rightmin.size()){
            rightmin.push(leftmax.top());
            leftmax.pop();
        }
        if(rightmin.size()>leftmax.size()){
            leftmax.push(rightmin.top());
            rightmin.pop();
        }
        if(leftmax.size()==rightmin.size()){
            median = (double)(leftmax.top() +rightmin.top())/2.0;
        }
        else{
            median = leftmax.top();
        }
    }
    
    double findMedian() {
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */