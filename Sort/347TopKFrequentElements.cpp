class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto n:nums) m[n]++;
        vector<vector<int>> v(nums.size()+1);
        for(auto item:m) v[item.second].push_back(item.first);
        vector<int> res;
        for(int i=v.size()-1; res.size()<k; i--){
            for(auto item:v[i]) res.push_back(item);
        }
        return res;
    }
};