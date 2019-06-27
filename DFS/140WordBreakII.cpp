class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string,vector<string>> m;
        return dfs(s, dict, m);
    }
    
    vector<string> dfs(string s, unordered_set<string> dict, unordered_map<string,vector<string>>& m){
        if(m.count(s)) return m[s];
        vector<string> res;
        if(s.empty()) return {""};
        for(auto word:dict){
            if(s.size() >= word.size() && s.substr(0, word.size()) == word){
                vector<string> subs = dfs(s.substr(word.size()), dict, m);
                for(auto sub:subs) res.push_back(word + (sub.size() ? " " + sub : ""));
            }
        }
        m[s] = res;
        return res;
    }
};