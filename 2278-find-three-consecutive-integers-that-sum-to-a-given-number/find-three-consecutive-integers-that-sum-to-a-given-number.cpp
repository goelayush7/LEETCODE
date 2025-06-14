class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        int rem = num%3;
        if(rem!=0){
            return {};
        }
        vector<long long>temp;
        long long start  = num/3;
        temp.push_back(start-1);
        temp.push_back(start);
        temp.push_back(start+1);
        return temp;

    }
};