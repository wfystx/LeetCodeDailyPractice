class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int pre = 0, cur = 0;
        for(int i=0; i<nums.size(); i++){
            int temp = max(pre+nums[i], cur);
            pre = cur;
            cur = temp;
        }

        return cur;
        
    }
};