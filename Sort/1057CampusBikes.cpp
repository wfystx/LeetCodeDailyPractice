class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int,int>>> bucket(2001);
        int m = workers.size(), n = bikes.size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                bucket[dis].push_back({i,j});
            }
        }     
        vector<int> res(m, -1);
        vector<bool> used(n, false);
        for(int d = 0; d <= 2000; d++){
            for(int k = 0; k < bucket[d].size(); k++){
                if(res[bucket[d][k].first] == -1 && !used[bucket[d][k].second]){
                    res[bucket[d][k].first] = bucket[d][k].second;
                    used[bucket[d][k].second] = true;
                }
            }
        }
        return res;
    }
    
};
