class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto i:instructions){
            if(i == 'G'){
                x += d[dir][0];
                y += d[dir][1];
            }else if(i == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
        return (x == 0 && y == 0) || dir > 0;
    }
};