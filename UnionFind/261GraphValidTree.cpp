class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        for(int i=0; i<n; i++) parents[i] = i;
        for(int i=0; i<edges.size(); i++){
            int e1 = find(parents, edges[i][0]);
            int e2 = find(parents, edges[i][1]);
            if(e1 == e2) return false;
            parents[e1] = e2;
        }
        return edges.size() == n-1;
    }
    int find(vector<int> parents, int x){
        if(parents[x] == x) return x;
        return find(parents, parents[x]);
    }
};