class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> cnt(K);
        cnt[0] = 1;
        int res = 0, prefix = 0;
        for(auto a:A){
            prefix = (prefix + a%K + K) % K;
            res += cnt[prefix]++;
        }
        return res;
    }
};