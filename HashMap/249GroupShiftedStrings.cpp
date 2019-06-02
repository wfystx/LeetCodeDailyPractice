class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> m;
        for(string s:strings) m[shift(s)].push_back(s);
        vector<vector<string>> res;
        for(auto item:m){
            vector<string> group = item.second;
            sort(group.begin(), group.end());
            res.push_back(group);
        }
        return res;
    }
private:
    string shift(string s){
        string t;
        for(int i=1; i<s.size(); i++){
            int diff = s[i] - s[i-1];
            if(diff < 0) diff += 26;
            t += 'a' + diff + ',';
        }
        return t;
    }
};