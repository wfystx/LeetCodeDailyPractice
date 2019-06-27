class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& stones) {
        parent.resize(stones.size());
        for(int i = 0; i < stones.size(); i++) parent[i] = i;
        for(int i = 0; i < stones.size(); i++)
            for(int j = i + 1; j < stones.size(); j++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) uni(i, j);
        int cnt = 0;
        for(int i = 0; i < stones.size(); i++) if(parent[i] == i) cnt++;
        return stones.size() - cnt;
    }
    int find(int x){
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    void uni(int x, int y){
        int i = find(x), j = find(y);
        if(i != j) parent[i] = j;
    }
};