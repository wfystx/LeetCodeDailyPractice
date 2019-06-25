class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> cnt(26,0), used(26,0);
        for(auto c:text) cnt[c - 'a'] ++;
        string res = "";
        for(auto c:text){
            cnt[c - 'a'] --;
            if(used[c - 'a'] ++ > 0) continue;
            while(!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0){
                used[res.back() - 'a'] = 0;
                res.pop_back();
            }
            res += c;
        }
        return res;
    }
};