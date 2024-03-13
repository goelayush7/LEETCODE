// class Solution {
// public:
//     int findsum(int i , int j ){
//         int sum=0;
//         for(int a = i ; a<=j ; a++) sum+=a;
//         return sum;
//     }
//     int pivotInteger (int n) {
//         if(n==1) return 1;
//         int start = 0;
//         int end = n;
//         while(start<=end){
//             int mid = (start+end)/2;
//             if(findsum(0,mid)==findsum(mid,n)){
//                 return mid;
//             }
//             if(findsum(0,mid)<findsum(mid,n)){
//                 start = mid+1;
//             }
//             else end = mid-1;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        double a = sqrt(sum);

        if (a - ceil(a) == 0)
            return int(a);
        else
            return -1;
    }
};