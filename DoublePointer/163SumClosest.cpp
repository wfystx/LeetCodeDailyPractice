class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min = INT_MAX, res;
        for(int i = 0; i < nums.size() - 2; i++){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < min){
                    res = sum;
                    min = abs(sum - target);
                } 
                if(sum < target) l++;
                else if(sum > target) r--;
                else return sum;
            }
        }
        return res;
    }
};