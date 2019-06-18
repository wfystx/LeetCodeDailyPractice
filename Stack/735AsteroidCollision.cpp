class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto i:asteroids){
            if(i > 0) res.push_back(i);
            else{
                while(!res.empty() && res.back() > 0 && res.back() < abs(i)) res.pop_back();
                if(res.empty() || res.back() < 0) res.push_back(i);
                else if(res.back() == -i) res.pop_back();
            }
        }
        return res;
    }
};