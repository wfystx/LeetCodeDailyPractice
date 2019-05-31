class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows == 0 ? 0 : matrix[0].size();
        vector<int> pre(cols + 1), cur(cols + 1);
        int res = 0;
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                if(matrix[i-1][j-1] == '1'){
                    cur[j] = min(min(pre[j-1],pre[j]),cur[j-1]) + 1;
                    res = max(res, cur[j]);
                }else cur[j] = 0;
            }
            swap(pre, cur);
        }
        return res*res;
    }
};