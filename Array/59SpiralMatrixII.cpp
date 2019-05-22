class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int cnt = 1;
        while(r1<=r2 && c1<=c2){
            for(int col=c1; col<=c2; col++) {
                res[r1][col] = cnt;
                cnt++;
            }
            for(int row=r1+1; row<=r2; row++) {
                res[row][c2] = cnt;
                cnt++;
            }
            for(int col=c2-1; col>c1; col--) {
                res[r2][col] = cnt;
                cnt++;
            }
            for(int row=r2; row>r1; row--) {
                res[row][c1] = cnt;
                cnt++;
            }
            r1++;r2--;c1++;c2--;
        }
        return res;
    }
};