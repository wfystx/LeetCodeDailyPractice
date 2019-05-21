class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        return helper(v, 1, n);
    }
    int helper(vector<vector<int>>& v, int start, int end){
        if(start>=end) return 0;
        if(v[start][end]!=0) return v[start][end];
        int res = INT_MAX;
        for(int k=start; k<end; k++){
            int temp = k + max(helper(v, start, k-1), helper(v, k+1, end));
            res = min(res,temp);
        }
        v[start][end] = res;
        return v[start][end];
    }
};