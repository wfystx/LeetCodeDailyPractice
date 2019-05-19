class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(auto w:words) um[w]++;
        vector<vector<string>> bucket(words.size()+1);
        for(auto u:um) bucket[u.second].push_back(u.first);
        int cnt = 0;
        vector<string> res;
        for(int i=0; i<=words.size(); i++){
            sort(bucket[i].begin(), bucket[i].end());
            reverse(bucket[i].begin(), bucket[i].end());
        }
        for(int i=words.size(); cnt<k; i--){
            while(!bucket[i].empty() && cnt<k){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                cnt++;
            }
        }
        return res;
    }
};