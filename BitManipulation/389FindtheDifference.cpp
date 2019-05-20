class Solution {
public:
    char findTheDifference(string s, string t) {
        char a = 0;
        for(auto c:s) a ^= c;
        for(auto c:t) a ^= c;
        return a;
        /*
        vector<int> m(26,0);
        for(auto c:s) m[c-'a']++;
        for(auto c:t){
            m[c-'a']--;
            if(m[c-'a']<0) return c;
        } 
        return ' ';
        */
    }
};