class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        vector<string> dic = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp = "";
        helper(digits, temp, 0, res, dic);
        return res;
    }
    void helper(string digits, string& temp, int pos, vector<string>& res, vector<string> dic){
        if(pos == digits.size()){
            res.push_back(temp);
            return;
        }
        int num = digits[pos]-'0';
        for(auto c:dic[num]){
            temp += c;
            helper(digits, temp, pos+1, res, dic);
            temp.erase(temp.size()-1);
        }
    }
};