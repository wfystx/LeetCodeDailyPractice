class Solution {
private:
    vector<vector<int>> m = {{4,6},
                             {6,8},
                             {7,9},
                             {4,8},
                             {3,9,0},
                             {},
                             {1,7,0},
                             {2,6},
                             {1,3},
                             {2,4}};
public:
    int knightDialer(int N) {
        long long mod = 1e9 + 7;
        vector<long long> pre(10, 1), cur(10, 0);
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j < 10; j++){
                cur[j] = 0;
                for(auto n:m[j]) cur[j] += pre[n];
                cur[j] %= mod;
            }
            swap(cur, pre);
        }
        return accumulate(pre.begin(), pre.end(), 0LL) % mod;
    }
};