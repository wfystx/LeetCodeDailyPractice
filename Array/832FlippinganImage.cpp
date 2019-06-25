class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& a:A) {
            reverse(a.begin(), a.end());
            for(auto& i:a) i ^= 1;
        }
        return A;
    }
};