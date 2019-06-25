class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        int mid = 0;
        while (mid < s.size() && m[s[mid]] >= k) ++mid;
        if (mid == s.size()) return mid;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < s.size() && m[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};