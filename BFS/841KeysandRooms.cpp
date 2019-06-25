class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int i = q.front(); q.pop();
            visited[i] = true;
            for(auto key:rooms[i]) if(visited[key] == false) q.push(key);
        }
        for(auto i:visited) if(i == false) return false;
        return true;
    }
};