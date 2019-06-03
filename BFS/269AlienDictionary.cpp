class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) return "";
        unordered_map<char,int> indegree;
        unordered_map<char,unordered_set<char>> graph;
        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].size(); j++)
                indegree[words[i][j]] = 0;
        for(int i=1; i<words.size(); i++){
            string cur = words[i - 1];
            string nxt = words[i];
            int len = min(cur.size(), nxt.size());
            for(int j=0; j<len; j++){
                if(cur[j] != nxt[j]){
                    if(graph[cur[j]].find(nxt[j]) == graph[cur[j]].end()){
                        graph[cur[j]].insert(nxt[j]);
                        indegree[nxt[j]]++;
                    }
                    break;
                }
            }
        }
        string res;
        queue<char> q;
        for(auto vertex:indegree){
            if(vertex.second == 0) 
                q.push(vertex.first);
        }
        while(!q.empty()){
            char cur = q.front(); q.pop();
            res += cur;
            if(graph[cur].size() != 0){
                for(auto vertex:graph[cur]){
                    indegree[vertex]--;
                    if(indegree[vertex] == 0) q.push(vertex);
                }
            }
        }
        return res.size() == indegree.size() ? res : "";
    }
};