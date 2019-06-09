class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size(), cnt = 0;
        unordered_map<int,int> m;
        for(int i=0; i<len; i++)
            for(int j=0; j<len; j++)
                m[A[i] + B[j]] ++;
        for(int i=0; i<len; i++)
            for(int j=0; j<len; j++)
                cnt += m[-(C[i] + D[j])];
        return cnt;
    }
};