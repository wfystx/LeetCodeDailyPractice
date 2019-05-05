class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for(auto i:intervals){
            m[i[0]]++;
            m[i[1]]--;
        }
        int count = 0, rev = 0;
        for(auto i:m){
            count += i.second;
            rev = max(rev, count);
        }
        return rev;
    }
};