class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int pre = 1, cur = 2, tmp;
        for(int i = 3; i <= n; i++){
            tmp = cur + pre;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};