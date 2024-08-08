class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count =0;
        int last = colors[0];
        int ans = 0;
        for(int i =1;i<n;i++){
            if(colors[i]!=last){
                count++;
            }
            if(colors[i]==last)count=1;
            if(count>=k) ans++;
            last = colors[i];
        }
        for(int i =0;i<k;i++){
            if(colors[i]!=last)count++;
            if(colors[i]==last)count=1;

            if(count>=k) ans++;
            last = colors[i];
        }
        return ans;
    }
};