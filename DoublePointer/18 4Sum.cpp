class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int sum = target - nums[i] - nums[j];
                int l = j+1, r = nums.size()-1;
                while(l<r){
                    if(nums[l]+nums[r]==sum){
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int a = nums[l], b = nums[r];
                        while(l<r && nums[l]==a) l++;
                        while(l<r && nums[r]==b) r--;
                    } 
                    else if(nums[l]+nums[r]>sum) r--;
                    else l++;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};