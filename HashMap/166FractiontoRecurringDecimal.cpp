class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        if(numerator > 0 ^ denominator > 0) res += "-";
        long n = labs(numerator), d = labs(denominator), r = n % d;
        res += to_string(n / d);
        if(!r) return res;
        res += ".";
        unordered_map<long,int> m;
        while(r){
            if(m.count(r)){
                res.insert(m[r], "(");
                res += ")";
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r / d);
            r %= d;
        }
        return res;
    }
};