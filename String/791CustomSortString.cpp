class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> m(26, 0);
        for(auto c:T) m[c - 'a']++;
        string res;
        for(auto c:S) while(m[c - 'a']-- > 0) res += c;
        for (char c = 'a'; c <= 'z'; ++c) {
            while (m[c - 'a'] -- > 0) res += c;
        }
        return res;
    }
};