/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfsser(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> res = split(data,',');
        int i=0;
        return dfds(res,i);
    }
private:
    void dfsser(TreeNode* root, string &res)
    {
        if(!root){
            res.append("N");
            res.append(",");
            return;
        }
        string v = to_string(root->val);
        res.append(v);
        res.append(",");
        dfsser(root->left,res);
        dfsser(root->right,res);
    }
    TreeNode* dfds(vector<string> v ,int &i)
    {
        if(v[i] == "N")
        {
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(v[i]));
        i++;
        node->left = dfds(v,i);
        node->right = dfds(v,i);
        return node;


    }
    vector<string> split(string &s,char c)
    {
        vector<string> res;
        stringstream ss(s);
        string item;
        while(getline(ss,item,c))
        {
            res.push_back(item);
        }
        return res;
    }
};
