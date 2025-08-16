class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans = 0;
        while(pq.size()>=2){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            ans++;
            top1--;
            top2--;
            if(top2>0)pq.push(top2);
            if(top1>0)pq.push(top1);
        }


        return ans;
    }
};