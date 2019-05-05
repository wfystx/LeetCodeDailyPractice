/**
 Solution:
 Use a multiset to store elements.
 lower_bound() returns the smallest value in set which is greater or equals to nums[i]-t. If the difference between it and nums[i] <= t. return true. If there is not such a value, insert the current nums[i] to set and if the size of set > k, erase the front to keep the set contains no more than k elements.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> m;
        for(int i=0; i<nums.size(); i++){
            auto a = m.lower_bound((long)nums[i]-(long)t);
            if(a!=m.end() && *a-(long)nums[i]<=(long)t) return true;
            m.insert(nums[i]);
            if(m.size()>k) m.erase(nums[i-k]);
        }
        return false;
    }
};