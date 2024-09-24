class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>set1;
        for(int i =0;i<arr1.size();i++){
            string str = to_string(arr1[i]);
            for(int j =0;j<str.size()+1;j++){
                set1.insert(str.substr(0,j));
            }
        }
        //find the prefixes of arr2;
        int len = 0;
        for(int i =0;i<arr2.size();i++){
            string str = to_string(arr2[i]);
            for(int j =0;j<str.size()+1;j++){
                string sub = str.substr(0,j);
                if(set1.find(sub)!=set1.end()){
                    int s = sub.size();
                    len=max(len,s);
                }
            }
        }
        return len;
    }
};