class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int pos){
        res.push_back(temp);
        for(int i=pos; i<nums.size(); i++){
            if(i==pos || nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
                helper(res, temp, nums, i+1);
                temp.pop_back();
            }
        }
    }
};