class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>> m;
        for(int i=0; i<words.size(); i++) m[words[i]].push_back(i);
        int i(0), j(0), res(INT_MAX);
        if(word1 == word2){
            j = 1;
            while(j < m[word1].size()){
                res = min(res, abs(m[word1][i] - m[word1][j]));
                i++; j++;
            }
        }else{
            while(i < m[word1].size() && j < m[word2].size()){
                res = min(res, abs(m[word1][i] - m[word2][j]));
                m[word1][i] < m[word2][j] ? i++ : j++;
            }
        }
        return res;
        
    }
};