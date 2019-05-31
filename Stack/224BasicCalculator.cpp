class Solution {
public:
    int calculate(string s) {
        stack<int> nums, signs;
        int res = 0, sign = 1, num = 0;
        for(char c:s){
            if(isdigit(c)) num = num*10 + (c - '0');
            else{
                res += sign * num;
                num = 0;
                if(c == '-') sign = -1;
                if(c == '+') sign = 1;
                if(c == '('){
                    nums.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                }
                if(c == ')'){
                    res = nums.top() + signs.top()*res;
                    signs.pop(); nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};