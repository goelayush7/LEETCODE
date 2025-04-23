class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cpy = capacity;
        int ans = 0;
        for(int i = 0;i<plants.size();i++){
            if(plants[i]<=cpy){
                cpy-=plants[i];
                ans++;
            }
            else{
                ans+=2*i+1;
                cpy = capacity;
                cpy -=plants[i];
            }
        }
        return ans;
    }
};