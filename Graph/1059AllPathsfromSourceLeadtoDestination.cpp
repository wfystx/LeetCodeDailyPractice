class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,unordered_set<int>> graph;
        unordered_map<int,int> visit;
        for(auto& e:edges) graph[e[0]].insert(e[1]);
        return dfs(graph, visit, source, destination);
    }
    bool dfs(unordered_map<int,unordered_set<int>>& graph, unordered_map<int,int>& visit, int i, int des){
        if(graph[i].empty()) return i == des;
        if(visit[i] == 1) return false;
        if(visit[i] == -1) return true;
        visit[i] = 1;
        for(auto n:graph[i])
            if(!dfs(graph, visit, n, des)) return false;
        visit[i] = -1;
        return true;
    }
};
