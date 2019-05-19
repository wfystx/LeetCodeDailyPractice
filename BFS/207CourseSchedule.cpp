class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = build(numCourses, prerequisites);
        vector degree = indegrees(g);
        for(int i=0; i<numCourses; i++){
            int j = 0;
            for(;j<numCourses; j++) if(degree[j]==0) break;
            if(j==numCourses) return false;
            degree[j]--;
            for(int v:g[j]) degree[v]--;
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    graph build(int numCourses, vector<vector<int>>& prerequisites){
        graph g(numCourses);
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    vector<int> indegrees(graph& g){
        vector<int> degree(g.size(),0);
        for(auto adj:g){
            for(auto v:adj){
                degree[v]++;
            }
        }
        return degree;
    }
};