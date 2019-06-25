class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> arr(26, 0);
        for(auto c:tiles) arr[c - 'A']++;
        return dfs(arr);
    }
    int dfs(vector<int>& arr){
        int sum = 0;
        for(int i = 0; i < 26; i++){
            if(arr[i] == 0) continue;
            sum ++;
            arr[i] --;
            sum += dfs(arr);
            arr[i] ++;
        }
        return sum;
    }
};