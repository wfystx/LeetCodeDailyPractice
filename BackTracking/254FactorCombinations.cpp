class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backTracking(res, temp, n, 2);
        return res;
    }
    void backTracking(vector<vector<int>>& res, vector<int>& temp, int n, int pos){
        if(n == 1 && temp.size() > 1){
            res.push_back(temp);
            return;
        }
        for(int i=pos; i<=n; i++){
            if(n % i == 0){
                temp.push_back(i);
                backTracking(res, temp, n/i, i);
                temp.pop_back();
            } 
        }
    }
};