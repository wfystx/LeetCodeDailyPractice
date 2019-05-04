/**
 Solution:
 Use sliding window to find the two elements sum up equal to 0 - nums[i].
 Sort the vector in advance.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rev;
        for(int i=0; i<nums.size(); i++){
            int target = 0 - nums[i];
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==target) {
                    rev.push_back({nums[i],nums[l],nums[r]});
                    int a = nums[l];
                    int b = nums[r];
                    while(l<r && nums[l] == a) l++;
                    while(l<r && nums[r] == b) r--;
                }else if(nums[l]+nums[r]>target){
                    r--;
                }else if(nums[l]+nums[r]<target){
                    l++;
                }
            }
        }
        sort(rev.begin(), rev.end());
        rev.erase(unique(rev.begin(),rev.end()), rev.end());
        return rev;
    }
};