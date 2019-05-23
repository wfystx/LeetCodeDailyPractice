class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, 0, nums);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, int pos, vector<int> nums){
        res.emplace_back(temp);
        for(int i=pos; i<nums.size(); i++){
            temp.emplace_back(nums[i]);
            helper(res, temp, i+1, nums);
            temp.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        for(int num:nums){
            int n = res.size();
            for(int i=0; i<n; i++){
                res.emplace_back(res[i]);
                res.back().emplace_back(num);
            }
        }
        return res;
    }
};