class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, last = -1;
        for(int i = 0 ; i < seats.size() ; i ++){
            if(seats[i] == 1){
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        res = max(res, int(seats.size()) - 1 - last);
        return res;
    }
};