class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int s2 = s.top(); s.pop();
                int s1 = s.top(); s.pop();
                if(tokens[i] == "+") s.push(s1+s2);
                if(tokens[i] == "-") s.push(s1-s2);
                if(tokens[i] == "*") s.push(s1*s2);
                if(tokens[i] == "/") s.push(s1/s2);
            }else s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};