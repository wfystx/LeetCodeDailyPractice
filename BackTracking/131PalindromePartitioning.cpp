class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s, res, tmp, 0);
        return res;
    }
    
    void dfs(string s, vector<vector<string>>& res, vector<string> tmp, int pos){
        if(pos == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = pos; i < s.size(); i++){
            if(check(s, pos, i)){
                tmp.push_back(s.substr(pos, i - pos + 1));
                dfs(s, res, tmp, i + 1);
                tmp.pop_back();
            }
        }
    }
    bool check(string s, int start, int end){
        while(start <= end)
            if(s[start++] != s[end--]) return false;
        return true;
    }
};