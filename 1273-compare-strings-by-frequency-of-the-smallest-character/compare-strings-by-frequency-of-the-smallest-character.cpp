class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>temp;
        for(auto it : words){
            string s = it;
            sort(s.begin(),s.end());
            char c = s[0];
            int i = 0;
            int count =0;
            while(i<s.size() && c==s[i]){
                count++;
                i++;
            }
            temp.push_back(count);
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        vector<int>out;
        for(auto it : queries){
            string s = it;
            sort(s.begin(),s.end());
            char c = s[0];
            int i = 0;
            int count =0;
            while(i<s.size() && c==s[i]){
                count++;
                i++;
            }
            int ans = 0;
            int j =0;
            while(j<temp.size() && temp[j]>count){
                ans++;
                j++;
            }   

            out.push_back(ans);
        }
        return out;

    }
};