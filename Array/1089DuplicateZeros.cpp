class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        for(int i = 0; i < len; i++)
            if(arr[i] == 0) arr.insert(arr.begin() + i++ + 1, 0);
        arr.resize(len);
    }
};