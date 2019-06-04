class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string,int> m;
        string word, res;
        int most = 0;
        for(auto &c:paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream is(paragraph);
        while(is >> word){
            if(!s.count(word)) m[word]++;
            most = max(most, m[word]);
        }
        for(auto item:m)
            if(item.second == most) res = item.first;
        return res;
        
    }
};