class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        for(int i =0;i<boxes.size();i++){
            for(int j = i+1;j<boxes.size();j++){
                if(boxes[j]=='1'){
                    ans[i]+=abs(j-i);
                }
            }
        }
        for(int i =boxes.size()-1;i>=0;i--){
            for(int j = i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    ans[i]+=abs(j-i);
                }
            }
        }
        return ans;
    }
};