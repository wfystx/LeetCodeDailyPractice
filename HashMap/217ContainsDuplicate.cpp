class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(auto n:nums) {
            if(m.find(n) == m.end()) m[n] = true;
            else return true;
        }
        return false;
    }
};