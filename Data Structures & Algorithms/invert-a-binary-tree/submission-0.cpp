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
    TreeNode* invertTree(TreeNode* root) {
      stack<TreeNode*>sc;
      if(root){sc.push(root);}
      while(sc.size())
      {
        TreeNode* curr = sc.top(); //since it it is iter , we use local var to travers
        sc.pop();
        swap(curr->left,curr->right);
        if(curr->left){sc.push(curr->left);}
        if(curr->right){sc.push(curr->right);}
      }
      return root;  
    }
};
