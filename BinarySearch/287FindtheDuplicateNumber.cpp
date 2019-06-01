class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1, mid, n;
        while(left < right){
            mid = left + (right - left) / 2, n = 0;
            for(auto num:nums) n += num <= mid;
            n <= mid ? left = mid + 1 : right = mid;
        }
        return left;
    }
};