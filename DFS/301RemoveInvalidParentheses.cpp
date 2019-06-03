class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        vector<char> par = {'(', ')'};
        helper(s, res, 0, 0, par);
        return res;
    }
    void helper(string s, vector<string>& res, int last_i, int last_j, vector<char>& par){
        for(int stack = 0, i = last_i; i<s.size(); i++){
            if(s[i] == par[0]) stack++;
            if(s[i] == par[1]) stack--;
            if(stack < 0){
                for(int j = last_j; j<=i; j++){
                    if(s[j] == par[1] && (j == last_j || s[j-1] != par[1]))
                        helper(s.substr(0,j) + s.substr(j+1), res, i, j, par);
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if(par[0] == '('){
            vector<char> newpar = {')', '('};
            helper(s, res, 0, 0, newpar);
        } else res.push_back(s);
    }
};