class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>> m;
        for(auto i:items) m[i[0]].push(i[1]);
        vector<vector<int>> res;
        for(auto s:m){
            int sum = 0;
            for(int i = 0; i < 5; i++){
                sum += s.second.top(); s.second.pop();
            }
            res.push_back({s.first, sum/5});
        }
        return res;
    }
};