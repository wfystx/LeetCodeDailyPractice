class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> dict(wordlist.begin(), wordlist.end());
        unordered_map<string,string> cap, vow;
        for(auto word:wordlist){
            cap.insert({tolow(word),word});
            vow.insert({devow(word),word});
        }
        for(auto &word:queries){
            if(dict.count(word)) continue;
            string lower = tolow(word), tovow = devow(word);
            if(cap.count(lower)) word = cap[lower];
            else if(vow.count(tovow)) word = vow[tovow];
            else word = "";
        }
        return queries;
    }
    
    string tolow(string word){
        for(auto &c:word) c = tolower(c);
        return word;
    }
    string devow(string word){
        word = tolow(word);
        for(auto &c:word) if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '#';
        return word;
    }
};