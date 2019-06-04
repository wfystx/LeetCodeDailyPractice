class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> pattern, next(cells.size(),0);
        for(int cycle = 0; N-- > 0; cycle++){
            for(int i=1; i<cells.size()-1; i++) next[i] = cells[i-1] == cells[i+1];
            if(cycle == 0) pattern = next;
            else if(pattern == next) N %= cycle;
            cells = next;
        }
        return cells;
    }
};