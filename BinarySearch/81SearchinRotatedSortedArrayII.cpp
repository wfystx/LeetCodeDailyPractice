class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(r>=l){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                l++;
                r--;
            }else if(nums[mid] <= nums[r]){
                if(nums[mid]<target && target<=nums[r]) l = mid+1;
                else r = mid-1;
            }else {
                if(nums[mid]>target && target>=nums[l]) r = mid-1;
                else l = mid+1;
            }
        }
        return false;
    }
};