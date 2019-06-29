class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int i = 0, j = A.size() - 1;
        for(int k = A.size() - 1; k >= 0; k--){
            if(abs(A[i]) > abs(A[j])) res[k] = A[i] * A[i++];
            else res[k] = A[j] * A[j--];
        }
        return res;
    }
};