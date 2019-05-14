/**
 Solution:
 Need to think more
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(m.find(sum-k)!=m.end()){
                cnt += m[sum-k];
            }
            m[sum]++;
        }
        return cnt;
    }
};