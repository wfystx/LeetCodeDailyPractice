/**
 Dynamic Programming
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rev = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            rev = max(rev, sum);
            if(sum<0) sum = 0;
        }
        return rev;
    }
};

/**
 Divide and Conquer
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    int helper(vector<int>& nums, int l, int r){
        if(l>r) return INT_MIN;
        int m = l + (r-l)/2, ml = 0, mr = 0;
        int mmll = helper(nums, l, m-1);
        int mmrr = helper(nums, m+1, r);
        for(int i=m-1, sum=0; i>=l; i--){
            sum += nums[i];
            ml = max(ml, sum);
        }
        for(int i=m+1, sum=0; i<=r; i++){
            sum += nums[i];
            mr = max(mr, sum);
        }
        return max(max(mmrr, mmll), ml+mr+nums[m]);
    }
};