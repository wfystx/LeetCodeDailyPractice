class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        if (s.size() == 1)
            return dp[0];
        if (s[1] == '0'){
            if (!(s[0]=='1' || s[0]=='2'))
                return 0;
            dp[1] = 1;
        }else{
            if (isValid(s[0], s[1]))
                dp[1] = 2;
            else
                dp[1] = 1;
        }
        if (s.size() == 2)
            return dp[1];
        for(int i=2; i<s.size(); i++){
            if (s[i] == '0'){
                if (!isValid(s[i - 1], s[i]))
                    return 0;
                dp[i] = dp[i - 2];
            }else{
                if (isValid(s[i - 1], s[i]))
                    dp[i] = dp[i - 1] + dp[i - 2];
                else
                    dp[i] = dp[i - 1];
            }
        }
        return dp[s.size()-1];
    }
    bool isValid(char first, char second){
        return first == '1' || (first == '2' && second <= '6');
    }
};