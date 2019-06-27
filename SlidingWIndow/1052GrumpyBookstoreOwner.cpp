class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int cnt = 0, add_cnt = 0, res = 0;
        for(int i = 0; i < customers.size(); i++){
            cnt += grumpy[i] ? 0 : customers[i];
            add_cnt += grumpy[i] ? customers[i] : 0;
            if(i >= X) add_cnt -= grumpy[i - X] ? customers[i - X] : 0;
            res = max(res, add_cnt);
        }
        return cnt + res;
    }
};