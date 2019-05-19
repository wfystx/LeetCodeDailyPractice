class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(n==0) return 0;
        int res = n;
        vector<int> parents(n,0);
        for(int i=0; i<n; i++) parents[i] = i;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(M[i][j]==1){
                    int p1 = find(i, parents);
                    int p2 = find(j, parents);
                    if(p1!=p2){
                        parents[p1] = p2;
                        res--;
                    } 
                }
            }
        }
        return res;
    }
private:
    int find(int x, vector<int>& parents){
        if(parents[x]==x) return x;
        return find(parents[x], parents);
    }
};