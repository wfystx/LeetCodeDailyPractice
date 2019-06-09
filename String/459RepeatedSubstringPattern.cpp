class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
    }
};
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() < 1) return false;
        for(int i=1; i<=s.size()/2; i++){
            if(s.size() % i == 0){
                string tmp = helper(s, i);
                if(tmp == s) return true;
            }
        }
        return false;
    }
    string helper(string s, int i){
        string ret = s.substr(i);
        ret += s.substr(0,i);
        return ret;
    }
};