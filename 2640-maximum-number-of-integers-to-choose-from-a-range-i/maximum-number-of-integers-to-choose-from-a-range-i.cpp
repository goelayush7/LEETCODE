class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st(banned.begin(),banned.end());
        long long cursum = 0;
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(st.find(i)==st.end()){
                int temp = cursum+i;
                if((temp)<=maxSum){
                    cout<<i<<endl;
                    cursum+=i;
                    ans++;
                }
                else break;
            }
        }
        return ans;


    }
};