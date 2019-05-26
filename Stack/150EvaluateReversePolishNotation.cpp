class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(auto t:tokens){
            if(!(t=="+" || t=="-" || t=="*" || t=="/")) stack.push_back(stoi(t));
            else {
                int n2 = stack.back(); stack.pop_back();
                if(t == "+") stack.back() += n2;
                else if(t == "-") stack.back() -= n2;
                else if(t == "*") stack.back() *= n2;
                else if(t == "/") stack.back() /= n2;
            }
        }
        return stack.back();
    }
};