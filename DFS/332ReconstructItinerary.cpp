class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> m;
        for(auto t:tickets){
            m[t[0]].insert(t[1]);
        }
        vector<string> res;
        dfs(m,"JFK",res);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(unordered_map<string,multiset<string>>& m, string s, vector<string>& res){
        while(!m[s].empty()){
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m,t,res);
        }
        res.push_back(s);
    }
};