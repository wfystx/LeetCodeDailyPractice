/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }
    
    void serialize(Node* root, ostringstream& os){
        if(!root) os << "#";
        else{
            os << root->val << " " << root->children.size() << " ";
            for(int i = 0; i < root->children.size(); i++)
                serialize(root->children[i], os);
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream is(data);
        return deserialize(is);
    }
    
    Node* deserialize(istringstream& is){
        string str = "", sz = "";
        is >> str;
        if(str == "#") return nullptr;
        is >> sz;
        Node* root = new Node(stoi(str), vector<Node*>());
        for(int i = 0; i < stoi(sz); i++)
            root->children.push_back(deserialize(is));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));