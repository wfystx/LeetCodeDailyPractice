class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size(), j = b.size(), cur = 0;
        string res;
        while(i || j || cur){
            cur += (i ? (a[(i--)-1]-'0') : 0) + (j ? (b[(j--)-1]-'0') : 0);
            res = char(cur%2 + '0') + res;
            cur /= 2;
        }
        
        return res;
    }
};