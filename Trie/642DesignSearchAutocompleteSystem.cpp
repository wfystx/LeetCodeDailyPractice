class TrieNode{
public:
    string str;
    int cnt;
    unordered_map<char, TrieNode*> child;
    TrieNode(): str(""), cnt(0) {}
};
class AutocompleteSystem {
public:
    struct cmp{
        bool operator() (pair<string, int>& a, pair<string, int>& b){
            return a.second<b.second || a.second==b.second && a.first>b.first;
        }
    };
    
    void insert(string& s, TrieNode* root, int times){
        TrieNode* cur = root;
        for(int i=0; i<s.size(); i++){
            if(!cur->child.count(s[i])) cur->child[s[i]] = new TrieNode();
            cur = cur->child[s[i]];
        }
        cur->cnt += times;
        cur->str = s;
    }
    
    void dfs(TrieNode* node){
        if(node->str != "") q.push({node->str, node->cnt});
        for(auto e:node->child) dfs(e.second);
    }
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        cur = root;
        s = "";
        for(int i=0; i<sentences.size(); i++)
            insert(sentences[i], root, times[i]);
        
    }
    
    vector<string> input(char c) {
        q = priority_queue<pair<string, int>, vector<pair<string, int> >, cmp>();
        if(c == '#'){
            insert(s, root, 1);
            s = "";
            cur = root;
            return {};
        }
        s += c;
        if(cur && cur->child.count(c)) cur = cur->child[c];
        else {
            cur = nullptr;
            return {};
        }
        if(cur->str != "") q.push({cur->str, cur->cnt});
        for(auto e:cur->child) dfs(e.second);
        
        vector<string> res;
        while(!q.empty() && res.size()<3){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
private:
    priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> q;
    TrieNode *cur, *root;
    string s;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */