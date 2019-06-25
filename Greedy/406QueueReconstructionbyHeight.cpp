class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for(auto p:people)
            res.insert(res.begin() + p[1], p);
        return res;
    }
};