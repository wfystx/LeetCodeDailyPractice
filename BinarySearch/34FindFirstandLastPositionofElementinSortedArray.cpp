class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> res{-1,-1};
        if(nums.size() == 0) return res;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(nums[l] == target) res[0] = l;
        else return res;
        r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2 + 1;
            if(nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        res[1] = r;
        return res;
    }
};