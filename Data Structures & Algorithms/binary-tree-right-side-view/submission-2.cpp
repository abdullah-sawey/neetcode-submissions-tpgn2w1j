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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root)
    {
        queue<TreeNode*>que;
        if(root){que.push(root);
        }
        while(que.size())
        {
            int len = que.size();
            for(int i=0;i<len;i++)
            {
            TreeNode* curr = que.front();
            que.pop();
            if(i==len-1){res.push_back(curr->val);}
            if(curr->left){que.push(curr->left);}
            if(curr->right){que.push(curr->right);}
            }

        }
        return res;
    }
};
