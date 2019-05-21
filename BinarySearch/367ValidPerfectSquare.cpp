class Solution {
public:
    bool isPerfectSquare(int num) {
        long r = num;
        while(r*r>num){
            r = (r + num/r)/2;
        }
        return r*r==num;
        /*
        for(long i=1; i<=num; i++){
            if(i*i==num) return true;
            if(i*i>num) return false;
        }
        return false;
        */
    }
};