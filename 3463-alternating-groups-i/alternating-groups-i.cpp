class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int i = 0;
        int j = 0;
        int n = colors.size();
        int count = 0;
        while(i<n){
            if(i==0){
                if(colors[i]==0){
                    if((colors[i+1]==1)&&colors[n-1]==1)count++;
                }
                if(colors[i]==1){
                    if((colors[i+1]==0)&&colors[n-1]==0)count++;
                }
            }
            else if(i==n-1){
                if(colors[i]==0){
                    if(colors[n-2]==1 && colors[0]==1)count++;
                }
                if(colors[i]==1){
                   if(colors[n-2]==0 && colors[0]==0)count++;
                }
            }
            else{
                if(colors[i]==0){
                    if(colors[i-1]==1 && colors[i+1]==1)count++;
                }
                if(colors[i]==1){
                    if(colors[i-1]==0 && colors[i+1]==0)count++;
                }
            }
            i++;
        }
        return count;
        
    }
};