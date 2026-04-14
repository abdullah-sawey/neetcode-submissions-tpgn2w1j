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
    bool isValidBST(TreeNode* root) {
        return func(root,-1000,1000);
    }

    bool func(TreeNode* root,int left,int right)
    {
        if(!root){return true;}
        if(!((root->val > left) &&( root->val <right)))
        {
            return false;
        }
        return func(root->left ,left,root->val)&&
        func(root->right,root->val,right); 
    }
};
