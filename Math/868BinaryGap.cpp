class Solution {
public:
    int binaryGap(int N) {
        int res = 0, cnt = 0;
        while((N & 1) == 0) N >>= 1;
        while(N != 0){
            if(N & 1 == 1){
                res = max(res, cnt);
                cnt = 0;
            }
            cnt ++;
            N >>= 1;
        }
        return res;
    }
};