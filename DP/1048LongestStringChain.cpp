class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string,int> m;
        int res = 0;
        for(auto w:words){
            int k = 0;
            for(int i = 0; i < w.size(); i++){
                string word = w.substr(0, i) + w.substr(i + 1);
                k = max(k, m[word] + 1);
            }
            m[w] = k;
            res = max(res, k);
        }
        return res;
    }
};