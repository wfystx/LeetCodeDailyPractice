class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre1 = 0, pre2 = 0, cur = 0, cnt = 0;
        int n = nums.size();
        while(true){
            if(++cur>=n) break;
            if(nums[cur]==nums[pre2]){
                if(pre1==pre2) pre2++;
                else {
                    nums.erase(nums.begin()+cur--);
                    n--;
                }
            } else {
                pre1 = cur; pre2 = cur;
            }
        }
        return nums.size();
    }
};