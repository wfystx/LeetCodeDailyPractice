class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n;
        if(m==0 || (n = matrix[0].size())==0) return false;
        int l = 0, r = m*n-1;
        while(r>=l){
            int mid = l + (r-l)/2;
            int e = matrix[mid/n][mid%n];
            if(target == e) return true;
            else if(target > e) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};