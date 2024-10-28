class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string>st(folder.begin(),folder.end());
        vector<string>ans;
        for(int i =0;i<folder.size();i++){
            string temp = folder[i];
            string copy =temp;
            bool flag = true;
            while(temp.size()>0){
                int index = temp.find_last_of('/');
                temp = temp.substr(0,index);

                if(st.find(temp)!=st.end()){
                    flag=false;
                }
            }
            if(flag)ans.push_back(copy);
        }
        return ans;
    }
};