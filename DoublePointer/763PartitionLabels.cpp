class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> map(26,0), res;
        for(int i=0; i<S.size(); i++) map[S[i] - 'a'] = i;
        int anchor = 0, maxIdx = -1;
        for(int i=0; i<S.size(); i++){
            maxIdx = max(maxIdx, map[S[i] - 'a']);
            if(maxIdx == i){
                res.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return res;
    }
};