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

    TreeNode *inorder(TreeNode *root,int k,int &depth){

        if(root == NULL) return NULL;

        TreeNode *left = inorder(root->left,k,depth);
        depth++;
        if(k == depth) return root;
        TreeNode *right = inorder(root->right,k,depth);

        if(left) return left;
        if(right) return right;
        return NULL;

    }

    int kthSmallest(TreeNode* root, int k) {
        
        int depth = 0;
        TreeNode *temp = inorder(root,k,depth);
        return temp->val;

    }
};