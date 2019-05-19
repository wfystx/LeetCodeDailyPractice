class Solution {
private:
    struct Node{
        double val;
        Node* parent;
        Node(){ parent = this; };
    };
    
    Node* findNode(Node* node){
        if(node->parent == node) return node;
        return findNode(node->parent);
    }
    
    void unionNodes(Node* n1, Node* n2, double num, unordered_map<string,Node*>& m){
        Node *p1 = findNode(n1), *p2 = findNode(n2);
        double ratio = num * n2->val / n1->val;
        for(auto node:m) if(findNode(node.second)==p1) node.second->val *= ratio;
        p1->parent = p2;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,Node*> m;
        vector<double> res;
        for(int i=0; i<equations.size(); i++){
            string s1 = equations[i][0], s2 = equations[i][1];
            if(m.find(s1)==m.end() && m.find(s2)==m.end()){
                m[s1] = new Node();
                m[s2] = new Node();
                m[s1]->val = values[i];
                m[s2]->val = 1;
                m[s1]->parent = m[s2];
            }else if(m.find(s1)==m.end()){
                m[s1] = new Node();
                m[s1]->parent = m[s2];
                m[s1]->val = m[s2]->val * values[i];
            }else if(m.find(s2)==m.end()){
                m[s2] = new Node();
                m[s2]->parent = m[s1];
                m[s2]->val = m[s1]->val / values[i];
            }else{
                unionNodes(m[s1], m[s2], values[i], m);
            }
        }
        for(auto q:queries){
            if(m.find(q[0]) != m.end() && m.find(q[1]) != m.end() && findNode(m[q[0]]) == findNode(m[q[1]])) res.push_back(m[q[0]]->val / m[q[1]]->val);
            else res.push_back(-1);
        }
        return res;
    }
};