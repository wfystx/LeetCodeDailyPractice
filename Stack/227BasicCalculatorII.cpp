class Solution {
public:
    int calculate(string s) {
        long num = 0;
        char sign = '+';
        stack<long> sta;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) num = num*10 + s[i]-'0';
            if((!isdigit(s[i]) && s[i]!=' ') || i == s.size()-1){
                if(sign == '-'){
                    num *= -1;
                }else if(sign == '*'){
                    num*=sta.top();
                    sta.pop();
                }else if(sign == '/'){
                    num = sta.top()/num;
                    sta.pop();
                }
                sta.push(num);
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        } 
        return res;
    }
};