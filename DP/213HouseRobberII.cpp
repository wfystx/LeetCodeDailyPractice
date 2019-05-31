class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return(max(helper(nums, 1, nums.size()-1), helper(nums, 0, nums.size()-2)));
    }
    int helper(vector<int>& nums, int start, int end){
        int pre = 0, cur = 0, sum = 0;
        for(int i=start; i<=end; i++){
            sum = max(pre+nums[i], cur);
            pre = cur;
            cur = sum;
        }
        return cur;
    }
};