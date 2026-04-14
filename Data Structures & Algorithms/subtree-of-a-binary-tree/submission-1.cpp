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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if(!subRoot){return true;}
        if(!root){return false;}
        if(sametree(root,subRoot)){return true;}
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); 
    }

    bool sametree(TreeNode* root, TreeNode* subRoot)
    {
        if((!root)&&(!subRoot)){return true;}
        if((!root)||(!subRoot)){return false;}
        if((root && subRoot) && (root->val != subRoot->val)){return false;}
        return sametree(root->left,subRoot->left)&&sametree(root->right,subRoot->right);
    }
};
