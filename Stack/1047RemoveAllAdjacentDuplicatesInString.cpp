class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(auto c:S){
            if(!s.empty() && c == s.top()) s.pop();
            else s.push(c);
        }
        string res = "";
        while(!s.empty()){
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};