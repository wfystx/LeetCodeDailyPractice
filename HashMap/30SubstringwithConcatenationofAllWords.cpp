class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        unordered_map<string,int> dict, m;
        for(auto word:words) dict[word] ++;
        int len_word = words[0].size(), len_str = len_word * words.size();
        vector<int> res;
        for(int i = 0; i < s.size() - len_str + 1; i ++){
            string w = s.substr(i, len_str);
            m = dict;
            for(int j = 0; j < len_str; j += len_word){
                string tmp = w.substr(j, len_word);
                if(m.count(tmp) && m[tmp] > 0){
                    m[tmp]--;
                    if(j + len_word == len_str) res.push_back(i);
                }else break;
            }
        }
        return res;
    }
};