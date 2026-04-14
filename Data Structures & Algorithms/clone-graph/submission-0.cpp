/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> old_new;
        return dfs(node,old_new);
    }
private:
    Node* dfs(Node * old, unordered_map<Node*,Node*>& old_new)
    {
        if(!old)
        {
            return nullptr;
        }
        if(old_new.count(old))
        {
            return old_new[old];
        }

        Node * nei = new Node(old->val);
        // insert in hash 
        old_new[old]= nei;
        
        for (auto node : old->neighbors)
        {
            nei->neighbors.push_back(dfs(node,old_new));
        }
        return nei;
    }
};
