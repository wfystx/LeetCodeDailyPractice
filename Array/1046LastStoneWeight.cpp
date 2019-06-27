class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while(stones.size() > 1){
            int a = stones.back(); stones.pop_back();
            int b = stones.back(); stones.pop_back();
            if(abs(a - b) != 0)
                stones.push_back(abs(a - b));
            sort(stones.begin(), stones.end());
        }
        return stones.empty() ? 0 : stones.back();
    }
};