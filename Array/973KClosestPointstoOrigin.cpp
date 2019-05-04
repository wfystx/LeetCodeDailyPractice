/**
 Solution:
 Simply sort it. There should be some faster ways.
*/
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return pow(a[0],2)+pow(a[1],2) < pow(b[0],2)+pow(b[1],2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};