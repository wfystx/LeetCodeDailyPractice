/**
 Solution:
 BFS way, every squar smaller than target consists a level. Search levels one by one to get the shortest path to target.
*/
class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> ps;
        vector<int> visited(n+1);
        queue<int> q;
        for(int i=1; i*i<=n; i++){
            ps.push_back(i*i);
            visited[i*i] = 1;
        }
        if(ps.back()==n) return 1;
        
        for(auto p:ps) q.push(p);
        int count = 1;
        while(!q.empty()){
            count++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int temp = q.front(); q.pop();
                for(auto pp:ps){
                    if(temp + pp == n) return count;
                    else if(temp + pp < n && visited[temp+pp]==0){
                        visited[temp+pp]=1;
                        q.push(temp+pp);
                    }else if(temp+pp>n) break;
                }
            }
        }
        return -1;
    }
};