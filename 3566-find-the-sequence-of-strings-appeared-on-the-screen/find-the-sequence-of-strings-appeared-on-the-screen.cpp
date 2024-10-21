class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string temp = "";
        for(auto it:target){
            temp+='a';
        }
        for(int i=0;i<target.size();i++){
            for(char ch='a';ch<=target[i];ch++){
                temp[i]=ch;
                ans.push_back(temp.substr(0,i+1));
            }
        }
        return ans;
        

    }
};