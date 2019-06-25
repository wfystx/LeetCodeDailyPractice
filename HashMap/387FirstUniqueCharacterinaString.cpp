class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        int res = INT_MAX;
        for(int i = 0 ; i < s.size(); i++){
            if(m.count(s[i])) m[s[i]] = -1;
            else m[s[i]] = i;
        }
        for(auto item:m)
            if(item.second != -1) res = min(res, item.second);
        return res == INT_MAX ? -1 : res;
    }
};