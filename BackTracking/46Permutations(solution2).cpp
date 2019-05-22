class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> nums, int pos){
        if(pos==nums.size()-1){
            res.emplace_back(nums);
            return;
        }
        for(int i=pos; i<nums.size(); i++){
            swap(nums[i], nums[pos]);
            helper(res, nums, pos+1);
        }
    }
};