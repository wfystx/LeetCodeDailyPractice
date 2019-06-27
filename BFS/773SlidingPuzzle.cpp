class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        vector<vector<int>> next = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string start = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
        queue<string> q;
        unordered_set<string> used;
        q.push(start);
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string cur = q.front(); q.pop();
                if(cur == target) return cnt;
                int zero = cur.find("0");
                for(auto n:next[zero]){
                    string tmp = cur;
                    swap(tmp[zero], tmp[n]);
                    if(used.count(tmp)) continue;
                    used.insert(tmp);
                    q.push(tmp);
                }
            }
            cnt ++;
        }
        return -1;
    }
};