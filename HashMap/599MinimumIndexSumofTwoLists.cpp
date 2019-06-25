class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m;
        for(int i = 0; i < list1.size(); i++) m[list1[i]] = i;
        int cnt = INT_MAX;
        vector<string> res;
        for(int i = 0; i < list2.size(); i++){
            if(m.count(list2[i])){
                if(cnt > i + m[list2[i]]){
                    res.clear();
                    cnt = i + m[list2[i]];
                    res.push_back(list2[i]);
                }else if(cnt == i + m[list2[i]]) res.push_back(list2[i]);
            }
        }
        return res;
    }
};