class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rev;
        string res = "";
        helper(n, 0, 0, res, rev);
        return rev;
    }
    void helper(int n, int l, int r, string res, vector<string>& rev){
        if(l==n && r==n) rev.push_back(res);
        if(l<n) helper(n, l+1, r, res+'(', rev);
        if(r<l) helper(n, l, r+1, res+')', rev);
    }
};