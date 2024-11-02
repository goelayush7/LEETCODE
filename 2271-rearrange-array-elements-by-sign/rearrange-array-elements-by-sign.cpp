class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (auto it : nums) {
            if (it > 0)
                pos.push_back(it);
            else
                neg.push_back(it);
        }
        vector<int> ans;
        bool flag = true;
        int i=0;
        while(i<pos.size()){
            if(flag){
                ans.push_back(pos[i]);
                flag=false;
            }
            if(flag==false){
                ans.push_back(neg[i]);
                flag=true;
            }
            i++;
        }
        return ans;
    }
};