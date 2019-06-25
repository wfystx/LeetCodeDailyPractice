class TrieNode{
public:
    TrieNode* child[26];
    int value;
    TrieNode(){
        memset(child, 0, sizeof(child));
        value = 0;
    }
};
class MapSum {
private:
    TrieNode* root;
    unordered_map<string,int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        for(auto c:key){
            if(node->child[c - 'a'] == nullptr) node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
            node->value += val - m[key];
        }
        m[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size() && node != nullptr; i++){
            node = node->child[prefix[i] - 'a'];
        }
        return node == nullptr ? 0 : node->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */