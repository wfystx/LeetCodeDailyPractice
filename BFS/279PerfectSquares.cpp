class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> ps;
        vector<int> visited(n+1,0);
        queue<int> q;
        for(int i=1; i*i<=n; i++){
            ps.push_back(i*i);
            visited[i*i] = 1;
        }
        if(ps.back() == n) return 1;
        for(auto p:ps) q.push(p);
        int cnt = 1;
        while(!q.empty()){
            cnt ++;
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q.front(); q.pop();
                for(auto num:ps){
                    if(tmp + num == n) return cnt;
                    else if(tmp + num < n && visited[tmp+num] == 0){
                        visited[tmp+num] = 1;
                        q.push(tmp+num);
                    }else if(tmp + num > n) break;
                }
            }
        }
        return 0;
    }
};