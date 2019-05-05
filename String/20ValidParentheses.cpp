/**
 Solution:
 Use stack.
*/
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='[') stack.push_back(s[i]);
            if(s[i]=='}' || s[i]==')' || s[i]==']'){
                if(stack.empty()) return false;
                char temp = stack.back();
                if((s[i]=='}' && temp=='{') || (s[i]==')' && temp=='(') || (s[i]==']' && temp=='[')) stack.pop_back();
                else return false;
            }
        }
        return stack.empty() ? true : false;
    }
};