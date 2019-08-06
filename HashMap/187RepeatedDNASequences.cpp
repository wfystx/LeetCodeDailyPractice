class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        vector<string> res;
        if(s.size() < 10) return res;
        for(int i = 0; i <= s.size() - 10; i++){
            string tmp = s.substr(i, 10);
            ++m[tmp];
        }
        for(auto item:m) if(item.second > 1) res.push_back(item.first);
        return res;
    }
};