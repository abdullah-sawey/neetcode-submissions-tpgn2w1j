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
    bool isBalanced(TreeNode* root) {
        bool res=1;
        dfs(root,res);
        return res;
    }

    int dfs(TreeNode* root,bool& res)
    {
        if(!root){return 0;}
        int left = dfs(root->left,res);
        int right = dfs(root->right,res);
        bool ans=0;
        if(abs(left - right)<=1)
        {
            ans = 1;
            res = min(res,ans);
        }
        else {res =0;}
        return 1+max(left, right);
    
    }
};
