class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string word, res;
        while(is >> word) res = word + " " + res;
        return res.substr(0, res.size() - 1);
    }
};