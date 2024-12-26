class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(auto it : nums){
            if(it>=0)pos.push_back(it);
            else if(it<0)neg.push_back(it);
        }
        int n = pos.size();
        int i =0;
        int j =0;
        bool flag= true;
        while(i<n || j<n){
            if(flag){
                ans.push_back(pos[i]);
                i++;
                flag = false;
            }
            else{
                ans.push_back(neg[j]);
                j++;
                flag=true;
            }
        }
        return ans;
    }
};