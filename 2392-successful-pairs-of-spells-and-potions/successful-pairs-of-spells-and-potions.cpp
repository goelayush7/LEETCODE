class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //     vector<vector<long long>>v;
    //     for(int i=0;i<spells.size();i++){
    //         vector<long long> v1(potions.size(), 0);
    //         for(int j =0; j<potions.size();j++){
    //             v1[j] = spells[i]*potions[j];
    //         }
    //         v.push_back(v1);
    //     }
    //    vector<int> ans(0);
    //     for(int i =0;i<v.size();i++){
    //         int count =0;
    //         for(int j = 0;j<v[0].size();j++ ){
    //             if(v[i][j]>=success) count++;
    //         }
    //         ans.push_back(count);
            
    //     }
    //     return ans;
        // vector<int>ans;
        // bool flag = 0;
        // sort(potions.begin(),potions.end());
        // for (int i = 0; i < spells.size(); i++) {
        //     bool flag = false;  // Reset flag for each spell
        //     for (int j = 0; j < potions.size(); j++) {
        //         if ((long long)spells[i] * potions[j] >= success) {
        //             ans.push_back(potions.size() - j);
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if (!flag) {
        //         ans.push_back(0);
        //     }
        // }

        // return ans;

        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n = spells.size();
        int m = potions.size();
        for(int i =0;i<n;i++){
            int start =0;
            int end = m-1;
            while(start<=end){
                int mid = (start+end)/2;
                if((long long)spells[i]*potions[mid]<success){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans.push_back(m-end-1);
        }
        return ans;
    }

};