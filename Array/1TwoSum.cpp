/*
 Solution:
 Use hash table to store each element and its index, at the same time, 
 look up in the hash table to find if the complement of current element 
 and target is already in the table. 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            int s = target - nums[i];
            if(map.find(s)!=map.end()) return {map[s], i};
            map[nums[i]] = i;
        }
        return {};
    }
};