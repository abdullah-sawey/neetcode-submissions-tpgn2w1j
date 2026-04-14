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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        if(root){qu.push(root);}
        while(qu.size())
        {

            vector<int> level;
            int len = qu.size();
            for(int i=0; i<len;i++)
            {
            TreeNode* curr = qu.front();
            qu.pop();
            level.push_back(curr->val);
            if(curr->left){qu.push(curr->left);}
            if(curr->right){qu.push(curr->right );}
            }
            if(!level.empty()){
            res.push_back(level);
            }
        }
        return res;
    }
};
