/**
 Solution:
 DFS
*/
class Solution {
private:
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size()==0) return 0;
        helper(nums, S, 0);
        return count;
    }
    void helper(vector<int>& nums, long S, int k){
        long S1 = S + nums[k];
        long S2 = S - nums[k];
        if(k==nums.size()-1){
            if(S1==0) count++;
            if(S2==0) count++;     
            return;
        }else{
            helper(nums, S1, k+1);
            helper(nums, S2, k+1);
        }
    }
};