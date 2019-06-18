class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = -1;
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(m.count(sum - k)) res = max(res, i - m[sum - k]);
            if(!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};