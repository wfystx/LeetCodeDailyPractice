class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0; i<input.size(); i++){
            char c = input[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> r1 = diffWaysToCompute(input.substr(0, i));
                vector<int> r2 = diffWaysToCompute(input.substr(i + 1));
                for(auto n1:r1){
                    for(auto n2:r2){
                        if(c == '+') res.push_back(n1 + n2);
                        else if(c == '-') res.push_back(n1 - n2);
                        else if(c == '*') res.push_back(n1 * n2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};