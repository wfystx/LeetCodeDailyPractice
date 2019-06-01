class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        vector<int> map(words.size(), 0);
        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].size(); j++)
                map[i] |= 1 << (words[i][j] - 'a');
        int res = 0;
        for(int i=0; i<words.size(); i++)
            for(int j=i+1; j<words.size(); j++)
                if((map[i] & map[j]) == 0) res = max(int(words[i].size()*words[j].size()), res);
        return res;
    }
};