class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> m(26,0);
        for(auto c:s) m[c-'a']++;
        for(auto c:t){
            m[c-'a']--;
            if(m[c-'a']<0) return c;
        } 
        return ' ';
    }
};