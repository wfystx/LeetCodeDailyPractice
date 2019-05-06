/**
 Solution:
 BFS
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> d(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;
        string s = "0000";
        if(d.find(s)!=d.end()) return -1;
        visited.insert(s);
        bfs.push(s);
        int res = 0;
        while(!bfs.empty()){
            int sz = bfs.size();
            for(int i=0; i<sz; i++){
                string temp = bfs.front();
                bfs.pop();
                vector<string> moves = helper(temp);
                for(auto m:moves){
                    if(m==target) {
                        return res+1;
                    }
                    if(visited.find(m)!=visited.end()) continue;
                    if(d.find(m)==d.end()){
                        bfs.push(m);
                        visited.insert(m);
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
    vector<string> helper(string key){
        vector<string> res;
        for(int i=0; i<4; i++){
            string temp = key;
            temp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(temp);
            temp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(temp);
        }
        return res;
    }
    
};