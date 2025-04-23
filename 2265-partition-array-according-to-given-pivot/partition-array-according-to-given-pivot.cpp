class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>temp1;
        vector<int>temp2;
        int piv = 0;
        for(auto it : nums){
            if(it==pivot)piv++;
            else if(it<pivot){
                temp1.push_back(it);
            }
            else temp2.push_back(it);
        }
        vector<int>ans;
        for(auto it : temp1){
            ans.push_back(it);
        }
        int  i =0;
        while(i<piv){
            ans.push_back(pivot);
            i++;
        }
        for(auto it : temp2){
            ans.push_back(it);
        }
        return ans;
    }
};