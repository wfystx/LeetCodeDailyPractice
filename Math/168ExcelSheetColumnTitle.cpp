class Solution {
public:
    string convertToTitle(int n) {
        return n==0 ? "" : convertToTitle((n-1)/26) + string{(n-1)%26 + 'A'};
    }
};