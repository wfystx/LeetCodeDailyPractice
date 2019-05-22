class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l = 1, r = x;
        while(true){
            long long mid = l+(r-l)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid>x) r = mid-1;
            else {
                if((mid+1)*(mid+1)>x) return mid;
                l = mid+1;
            }
        }
    }
};