class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        string res;
        int cycle = 2*numRows - 2;
        for(int i=0; i<numRows; i++){
            for(int j=i; j<s.size(); j+=cycle){
                res += s[j];
                int second = (j-i) + cycle - i;
                if(i!=0 && i!=numRows-1 && second<s.size()) res += s[second];
            }
        }
        return res;
    }
};