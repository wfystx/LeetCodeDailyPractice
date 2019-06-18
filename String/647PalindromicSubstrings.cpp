class Solution {
public:
    int cnt = 0;
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        for(int i = 0; i < s.size(); i++){
            count(s, i, i);
            count(s, i, i + 1);
        }
        return cnt;
    }
    
    void count(string s, int start, int end){
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            start--; end++; cnt++;
        }
    }
};