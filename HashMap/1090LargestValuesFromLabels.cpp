class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        multimap<int,int> s;
        unordered_map<int,int> m;
        int res = 0;
        for(int i = 0; i < values.size(); i++) s.insert({values[i],labels[i]});
        for(auto it = rbegin(s); it != rend(s) && num_wanted > 0; it++){
            if(++m[it->second] <= use_limit){
                res += it->first;
                num_wanted--;
            }
        }
        return res;
    }
};