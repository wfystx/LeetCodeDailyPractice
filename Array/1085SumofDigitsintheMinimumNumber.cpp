class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int s = INT_MAX, sum = 0;
        for(auto a:A) s = min(s, a);
        while(s != 0){
            sum += s%10;
            s /= 10;
        }
        return sum % 2 == 0 ? 1 : 0;
    }
};