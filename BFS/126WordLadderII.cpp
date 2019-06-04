class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end()), visited;
        vector<vector<string>> res;
        if(!dict.count(endWord)) return res;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int minLevel = INT_MAX, level = 1;
        while(!paths.empty()){
            vector<string> path = paths.front(); paths.pop();
            if(path.size() > minLevel) break;
            if(path.size() > level){
                for(auto v:visited) dict.erase(v);
                visited.clear();
                level = path.size();
            }
            string word = path.back();
            for(int i=0; i<word.size(); i++){
                char c = word[i];
                for(int j=0; j<26; j++){
                    word[i] = 'a' + j;
                    if(dict.count(word)){
                        vector<string> tmp(path);
                        tmp.push_back(word);
                        visited.insert(word);
                        if(word == endWord){
                            minLevel = level;
                            res.push_back(tmp);
                        }else paths.push(tmp);
                    }
                }
                word[i] = c;
            }
        }
        return res;
    }
};