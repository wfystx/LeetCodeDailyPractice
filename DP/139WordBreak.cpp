class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        if(wordDict.size()==0) return false;
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    if(m.find(word)!=m.end()){
                        cout << word << endl;
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    /* recursion solution but TLE
    bool flag = false;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        helper(s, m, 0);
        return flag;
    }
    void helper(string s, unordered_set<string> m, int index){
        if(index == s.size()) flag = true;
        for(int i=index; i<s.size(); i++){
            if(m.find(s.substr(index, i-index+1)) != m.end()){
                helper(s, m, i+1);
            }
        }
    }
    */
};