class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        while(n!=0){
            res += (n%10)*(n%10);
            n /= 10;
        }
        if(res==4) return false;
        else if(res==1) return true;
        return isHappy(res);
    }
};