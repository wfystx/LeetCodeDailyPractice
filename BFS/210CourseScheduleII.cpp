class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        vector<int> res;
        for(int i=0; i<prerequisites.size(); i++) 
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for(int i=0; i<numCourses; i++)
            for(auto vertex:graph[i])
                degree[vertex]++;
        for(int i=0, j; i<numCourses; i++){
            for(j=0; j<numCourses; j++) if(degree[j] == 0){
                res.push_back(j);
                break;
            } 
            if(j == numCourses) return {};
            degree[j]--;
            for(auto vertex:graph[j]) degree[vertex]--;
        }
        return res;
    }
};