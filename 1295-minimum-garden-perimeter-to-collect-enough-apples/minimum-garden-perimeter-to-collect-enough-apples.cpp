class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long i = 0;
        long long x = 0;
 
        while(x < neededApples){
            i++;   
            x += (long long) 12*pow(i,2); 
            
        }
        return (long long) (i)*8;
    }
};