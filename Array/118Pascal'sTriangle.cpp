class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 2; i <= numRows; i++){
            vector<int> tmp;
            for(int j = 1; j <= i; j++){
                if(j == 1 || j == i) tmp.push_back(1);
                else tmp.push_back(res[i - 2][j - 2] + res[i - 2][j - 1]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};