class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26);
        for(int i = 0; i < order.size(); i++) m[order[i] - 'a'] = i;
        for(auto& word:words)
            for(auto& c:word)
                c = m[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};