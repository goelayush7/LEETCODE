class Solution {
public:
    string fractionAddition(string expression) {
        int numerator =0;
        int denominator =1;
        int n = expression.size();
        int i =0;
        while(i<n){        
            int sign= 1;
            if(expression[i]=='-' || expression[i]=='+'){
                if(expression[i]=='-')sign=-1;
                i++;
            }
            int num =0;
            while(i<n && isdigit(expression[i])){
                num = num*10+(expression[i]-'0');
                i++;
            }
            num *=sign;
            i++;
            int deno =0;
            while(i<n && isdigit(expression[i])){
                deno = deno*10+(expression[i]-'0');
                i++;
            }
            numerator = numerator*deno +num*denominator;
            denominator = deno*denominator;

            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }
         return to_string(numerator) + "/" + to_string(denominator);
        
    }
};