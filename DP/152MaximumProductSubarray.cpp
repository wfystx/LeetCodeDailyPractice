class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpmax(nums.size()), dpmin(nums.size());
        int res = dpmax[0] = dpmin[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > 0){
                dpmax[i] = max(dpmax[i-1]*nums[i], nums[i]);
                dpmin[i] = min(dpmin[i-1]*nums[i], nums[i]);
            }else {
                dpmax[i] = max(dpmin[i-1]*nums[i], nums[i]);
                dpmin[i] = min(dpmax[i-1]*nums[i], nums[i]);
            }
            res = max(res, dpmax[i]);
        }
        return res;
    }
};