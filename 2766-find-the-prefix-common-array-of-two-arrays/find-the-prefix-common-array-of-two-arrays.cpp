class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        vector<int>ans;
        int n = A.size();
        for(int i = 0;i<n;i++){
            int count = 0;
            st1.insert(A[i]);
            st2.insert(B[i]);
            for(auto it : st1){
                if(st2.find(it)!=st2.end()){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};