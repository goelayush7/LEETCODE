class Solution {
public:
    int myAtoi(string s) {
        unordered_map<char, int> maps;
        for (int i = 0; i < 10; i++) {
            maps['0' + i] = i;
        }
        int n = s.size();
        int index=0;
        while(index<n && s[index]==' '){
            index++;
        }
        bool negative =false;
        if(index<n && s[index]=='-'){
            negative=true;
            index++;
        }
        if(index<n && s[index]=='+' && negative==false){
            index++;
        }
        int num=0;
        while(index<n && maps.find(s[index])!=maps.end()){
           int digit = maps[s[index]];
           if (num > (INT_MAX - maps[s[index]]) / 10) {
                return negative ? INT_MIN : INT_MAX;
            }
            num = num*10+digit;
            index++;
        }
        if(negative) return -num;
        return num;

    }
};