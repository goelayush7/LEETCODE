class Solution {
public:
    int helper(string s){
        int n = s.size();
        if(s == "1"){
            return 0;
        }

        //even
        int result = 0;
        if(s[n-1] == '0'){
            result = 1 + helper(s.substr(0, n-1));
        }
        else {
            // Handle the binary addition of '1' to s
            bool carry = true;
            for(int i = n - 1; i >= 0 && carry; --i){
                if(s[i] == '1'){
                    s[i] = '0';
                }
                else {
                    s[i] = '1';
                    carry = false;
                }
            }
            if(carry){
                s = '1' + s;
            }
            result = 1 + helper(s);
        }
        return result;
    }

    int numSteps(string s) {
        return helper(s);
    }
};
