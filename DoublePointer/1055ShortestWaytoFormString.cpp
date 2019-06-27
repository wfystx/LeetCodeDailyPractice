class Solution {
public:
    int shortestWay(string source, string target) {
        int res = 0, t = 0;
        while(t < target.size()){
            int pt = t;
            for(int s = 0; s < source.size(); s++)
                if(t < target.size() && source[s] == target[t]) t++;
            if(t == pt) return -1;
            res ++;
        }
        return res;
    }
};