class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>maps2;
        for(auto words : words2){
            unordered_map<char,int>maps3;

            for(auto word:words){
                maps3[word]++;
            }
            for(auto it : maps3){
                if(maps2.find(it.first)!=maps2.end()){
                    maps2[it.first] = max(maps2[it.first],it.second);
                }
                else{
                    maps2[it.first] = it.second;
                }
            }
        }
        vector<string>ans;
        for(auto words : words1){
            unordered_map<char,int>maps1;
            for(auto c : words){
                maps1[c]++;
            }
            bool flag = true;
            for(auto it : maps2){
                char c = it.first;
                if(maps1[c]<it.second){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words);
            }
        }
        return ans;
    }
};