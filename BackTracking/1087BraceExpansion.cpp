class Solution {
public:
    vector<string> res;
    vector<string> expand(string S) {
        string cur = "";
        dfs(S, cur, 0);
        return res;
    }
    
    void dfs(string& s, string& cur, int idx) {
        if (idx == s.size()) {
            if(cur.size() > 0) res.push_back(cur);
            return;
        }

        vector<char> letters;
        if (s[idx] == '{') {
            while (s[++idx] != '}')
                if (isalpha(s[idx])) letters.push_back(s[idx]);
        } else 
            letters.push_back(s[idx]);

        sort(letters.begin(), letters.end());
        for (char c : letters) {
            cur.push_back(c);
            dfs(s, cur, idx+1);
            cur.pop_back();
        }
    }
};