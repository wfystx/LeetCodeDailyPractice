class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //If i is odd, then nums[i] >= nums[i - 1];
        //If i is even, then nums[i] <= nums[i - 1].
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(((i&1) && nums[i] < nums[i-1]) || (!(i&1) && nums[i] > nums[i-1]))
                swap(nums[i], nums[i-1]);
        }
    }
};