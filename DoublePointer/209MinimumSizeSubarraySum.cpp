class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum = 0, res = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum>=s){
                res = min(res, i+1-start);
                sum -= nums[start++];
            }
        }
        return res == INT_MAX ? 0 : res;
        
    }
};