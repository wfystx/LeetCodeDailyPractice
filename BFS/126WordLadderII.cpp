class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;
        unordered_set<string> visited;
        while(!paths.empty()){
            vector<string> path = paths.front(); paths.pop();
            if(path.size() > minLevel) break;
            if(path.size() > level){
                for(string v:visited) dict.erase(v);
                visited.clear();
                level = path.size();
            }
            string word = path.back();
            for(int i=0; i<word.size(); i++){
                char c = word[i];
                for(int k=0; k<26; k++){
                    word[i] = 'a' + k;
                    if(dict.find(word) != dict.end()){
                        vector<string> newPath = path;
                        newPath.push_back(word);
                        visited.insert(word);
                        if(word == endWord) {
                            minLevel = level;
                            res.push_back(newPath);
                        }else paths.push(newPath);
                    }
                    word[i] = c;
                }
            }
        }
        return res;
    }   
};