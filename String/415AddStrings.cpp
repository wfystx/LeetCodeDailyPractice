class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry){
            int n = (i >= 0 ? (num1[i--] - '0') : 0) + (j >= 0 ? (num2[j--] - '0') : 0) + carry;
            carry = n / 10;
            res = to_string(n % 10) + res;
        }
        return res;
    }
};