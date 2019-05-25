class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        if(s[1] == '0'){
            if(!(s[0] == '1' || s[0] == '2')) return 0;
            dp[1] = 1;
        }else{
            if(check(s[0], s[1])) dp[1] = 2;
            else dp[1] = 1;
        }
        for(int i=2; i<s.size(); i++){
            if(s[i] == '0'){
                if(!check(s[i-1], s[i])) return 0;
                else dp[i] = dp[i-2]; 
            }else {
                if(check(s[i-1], s[i])) dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            }
        }
        return dp[s.size()-1];

    }
    bool check(char a, char b){
        return a == '1' || (a == '2' && b <= '6');
    }
};