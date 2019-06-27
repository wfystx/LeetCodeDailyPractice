class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> s = {0};
        for(int i = 0; i < stones.size(); i++){
            int stone = stones[i];
            auto t = s;
            s.clear();
            for(auto n:t){
                s.insert(n + stone);
                s.insert(n - stone);
            }
        }
        int res = INT_MAX;
        for(auto n:s) res = min(res, abs(n));
        return res;
    }
};