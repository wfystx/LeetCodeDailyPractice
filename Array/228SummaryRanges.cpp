class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int k, i = 0;
        vector<string> res;
        while(i < nums.size()){
            k = i;
            while(k<nums.size()-1 && nums[k] == nums[k+1] - 1) k++;
            if(k == i) res.push_back(to_string(nums[i]));
            else res.push_back(to_string(nums[i]) + "->" + to_string(nums[k]));
            i = k + 1;
        }
        return res;
    }
};