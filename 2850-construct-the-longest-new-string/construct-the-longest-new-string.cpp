class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans =0;
        if(x<y){
            ans+=min(y,x+1);
            ans+=x;
            ans = ans*2;
        }
        else{
            ans+=min(y+1,x);
            ans+=y;
            ans=ans*2;
        }
        ans+=2*z;
        return ans;

    }
};