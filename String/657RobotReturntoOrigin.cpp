class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for(auto c:moves){
            if(c == 'U') v++;
            if(c == 'D') v--;
            if(c == 'R') h++;
            if(c == 'L') h--;
        }
        return h == 0 && v == 0;
    }
};