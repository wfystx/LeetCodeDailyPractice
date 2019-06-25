class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;        
        for(int i = 0; i < nums.size(); i++){
            int val = abs(nums[i]) - 1;
            nums[val] = - nums[val];
            if(nums[val] > 0) res.push_back(abs(nums[i]));
        }
        return res;
    }
};