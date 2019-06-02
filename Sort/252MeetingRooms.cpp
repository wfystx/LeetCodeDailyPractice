class Solution {
private:
    static bool cmp(vector<int> i1, vector<int> i2){
        return i1[0] < i2[0];
    }
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i=1; i<intervals.size(); i++) 
            if(intervals[i-1][1] > intervals[i][0]) return false;
        return true;
    }
};