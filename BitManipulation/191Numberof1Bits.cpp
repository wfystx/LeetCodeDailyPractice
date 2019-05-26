class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t mask = 1;
        for(int i=0; i<32; i++){
            if((n&mask) != 0) cnt++;
            mask <<= 1;
        }
        return cnt;
    }
};