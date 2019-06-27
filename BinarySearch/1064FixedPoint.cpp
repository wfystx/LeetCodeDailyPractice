class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(A[m] == m) return m;
            else if(A[m] < m) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};