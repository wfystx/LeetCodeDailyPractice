class Solution {
public:
    int divide(int dividend, int divisor) {
        long dvd = labs(dividend), dvs = labs(divisor), res = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while(dvd>=dvs){
            long temp = dvs, m = 1;
            while(temp<<1 <= dvd){
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            res += m;
        }
        if(res*sign<INT_MIN || res*sign>INT_MAX) return INT_MAX;
        return res*sign;
    }
};