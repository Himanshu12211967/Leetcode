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

    int max_depth = 0;

    void preorder(TreeNode *root,int lvl){
        if(!root) return;

        max_depth = max(max_depth,lvl);
        preorder(root->left,lvl+1);
        preorder(root->right,lvl+1);

    }

    int maxDepth(TreeNode* root) {
        preorder(root,1);
        return max_depth;
    }
};