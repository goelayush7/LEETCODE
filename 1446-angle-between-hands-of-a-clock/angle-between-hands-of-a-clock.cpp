class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourdegree = hour*30;
        double hourmin = minutes*6;
        hourdegree+=minutes*0.5;
        if(hourdegree>360)hourdegree = hourdegree-360;
        double value = abs(min(hourdegree-hourmin,hourmin-hourdegree));
        return min(value,abs(360-value));
    }
};