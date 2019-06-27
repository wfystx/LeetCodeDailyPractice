class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int res = 0;
        long l = stol(L), r = stol(R);
        helper("", res, l, r);
        for(int i = 0; i < 10; i ++){
            char c = i + '0';
            helper(string(1,c), res, l, r);
        }
        return res;
    }
    void helper(string s, int& res, long l, long r){
        if(s.size() > 9) return;
        if(!s.empty() && s[0] != '0'){
            long cur = stol(s), pow_cur = cur * cur;
            if(pow_cur > r) return;
            if(pow_cur >= l && is_palindrome(to_string(pow_cur))) res++;
        }
        for(int i = 0; i < 10; i ++){
            char c = i + '0';
            helper(c + s + c, res, l, r);
        }
            
    }
    bool is_palindrome(string s){
        int l = 0, r = s.size() - 1;
        while(l < r) if(s[l++] != s[r--]) return false;
        return true;
    }
};