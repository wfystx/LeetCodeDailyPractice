class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int cnt = 0;
        for(auto t:tasks){
            m[t] ++;
            cnt = max(cnt,m[t]);
        }
        int res = (cnt - 1) * (n + 1);
        for(auto item:m)
            if(item.second == cnt) res++;
        return max(res, (int)tasks.size());
    }
};