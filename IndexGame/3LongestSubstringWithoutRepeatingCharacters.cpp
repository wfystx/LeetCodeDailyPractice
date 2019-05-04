/**
 Solution:
 Define a mapping of the characters to its index. Then we can skip the characters immediately when we found a repeated character. Start with the non repeated position.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
        int start = -1;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(map[s[i]]>start) start = map[s[i]];
            map[s[i]] = i;
            count = max(count, i-start);
        }
        return count;
    }
};