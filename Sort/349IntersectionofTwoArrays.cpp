/**
 Solution:
 use unordered_map
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> rev;
        for(auto n:nums2){
            if(m.find(n)!=m.end()){
                rev.push_back(n);
                m.erase(n);
            }
        }
        return rev;
    }
};