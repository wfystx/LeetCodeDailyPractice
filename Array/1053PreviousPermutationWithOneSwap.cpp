class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 1, j = i;
        for(; i > 0 && A[i] >= A[i - 1]; i--);
        if(i-- == 0) return A;
        
        for(; A[j] >= A[i]; j--);
        for(; A[j] == A[j - 1]; j--);
        swap(A[i], A[j]);
        return A;
    }
};