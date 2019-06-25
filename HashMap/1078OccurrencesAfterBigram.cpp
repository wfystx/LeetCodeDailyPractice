class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream is(text);
        string pre, cur, word;
        vector<string> res;
        while(is >> word){
            if(pre == first && cur == second) res.push_back(word);
            pre = cur; 
            cur = word;
        }
        return res;
    }
};