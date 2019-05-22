class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1 ) return 1;  
        if(x == -1 && n%2 != 0) return -1;
        if(x == -1 && n%2 == 0) return 1;       
        if(n<0){
            if(n==INT_MIN) n = INT_MAX;
            else n = -n;
            x = 1/x;
        }
        return n%2 ? x*myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};