class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = n;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down = 0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            sum-=min(down,peak);
        }
        return sum;
    }
};