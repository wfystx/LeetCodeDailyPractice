class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int tmp = 1, cnt = 0;
        for(int i = 0, j = 0; j < nums.size(); j++){
            tmp *= nums[j];
            while(i <= j && tmp >= k) tmp /= nums[i++];
            cnt += j - i + 1;
        }
        return cnt;
    }
};