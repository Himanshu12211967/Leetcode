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

    TreeNode *Parent(TreeNode *root, int node){

        if(root == NULL || root->val == node) return NULL;
        if(root->left && root->left->val == node) return root;
        if(root->right && root->right->val == node) return root;

        TreeNode *left = Parent(root->left, node);
        TreeNode *right = Parent(root->right, node);

        if(left == NULL && right == NULL) return NULL;
        if(left) return left;
        return right;

    }

    int level(TreeNode *root, int node, int lvl){

        if(root == NULL) return -1;
        if(root->val == node) return lvl;

        int left = level(root->left,node,lvl+1);
        int right = level(root->right,node,lvl+1);

        if(left == -1 && right == -1) return -1;
        if(left != -1) return left;
        return right;
    }

    bool isCousins(TreeNode* root, int x, int y) {

        bool isSameLevel = (level(root,x,1) == level(root,y,1));
        bool notSameParnent = (Parent(root,x) != Parent(root,y));
        return isSameLevel && notSameParnent;
    }
};