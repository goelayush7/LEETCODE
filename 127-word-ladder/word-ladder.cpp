class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        int steps =1;
        q.push({beginWord,steps});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            auto it  = q.front();
            string word = it.first;
            steps = it.second;
            q.pop();
            if(word==endWord)return steps;
            for(int i =0;i<word.size();i++){
                char ch = word[i];
                for(char c ='a' ; c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};