class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, reach = 0, n = nums.size();
        for(; i<n && i<=reach; i++) reach = max(nums[i]+i, reach);
        return i==n;
    }
};