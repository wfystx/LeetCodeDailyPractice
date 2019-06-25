class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        for(auto c:s) dict[c] ++;
        string res = "0";
        for(auto c:s){
            dict[c] --;
            if(visited[c] == true) continue;
            while(c < res.back() && dict[res.back()]){
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};