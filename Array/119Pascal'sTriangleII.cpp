class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        if(rowIndex == 0) return res[0];
        for(int i = 1; i <= 33; i++){
            vector<int> tmp;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) tmp.push_back(1);
                else tmp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            if(i == rowIndex) return tmp;
            res.push_back(tmp);
        }
        return {};
    }
};