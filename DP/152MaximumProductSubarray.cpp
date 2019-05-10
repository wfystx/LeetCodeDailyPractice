class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpmax(nums.size());
        vector<int> dpmin(nums.size());
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>0){
                dpmax[i] = max(nums[i], dpmax[i-1]*nums[i]);
                dpmin[i] = min(nums[i], dpmin[i-1]*nums[i]);
            }else{
                dpmax[i] = max(nums[i], dpmin[i-1]*nums[i]);
                dpmin[i] = min(nums[i], dpmax[i-1]*nums[i]);
            }
        }
        int rev = INT_MIN;
        for(int i=0; i<dpmax.size(); i++){
            rev = max(rev, dpmax[i]);
        }
        return rev;
    }
};