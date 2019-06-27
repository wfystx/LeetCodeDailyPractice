class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] - m - k >= nums[0]) r = m;
            else l = m + 1;
        }
        return nums[0] + l + k - 1;
    }
};