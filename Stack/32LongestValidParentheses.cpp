class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stc;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') stc.push(i);
            else{
                if(!stc.empty() && s[stc.top()]=='('){
                    stc.pop();
                    int leftmost = -1;
                    if(!stc.empty()) leftmost = stc.top();
                    res = max(res, i-leftmost);
                }else stc.push(i);
            }
        }
        return res;
    }
};