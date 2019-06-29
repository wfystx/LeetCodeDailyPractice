class Solution {
public:
    static bool cmp(pair<char,int>& p1, pair<char,int>& p2){
        return p1.second > p2.second;
    }
    string reorganizeString(string S) {
        int n = S.size();
        unordered_map<char,int> m;
        for(auto c:S){
            m[c]++;
            if(m[c] > (n + 1) / 2) return "";
        }
        vector<pair<char,int>> v;
        for(auto item:m) v.push_back({item.first, item.second});
        sort(v.begin(), v.end(), cmp);
        string s, res;
        for(auto i:v) s += string(i.second, i.first);
        for(int i = 0, j = (n - 1) / 2 + 1; i <= (n - 1) / 2; i++, j++){
            res += s[i];
            if(j < n) res += s[j];
        }
        return res;
        
        
    }
};