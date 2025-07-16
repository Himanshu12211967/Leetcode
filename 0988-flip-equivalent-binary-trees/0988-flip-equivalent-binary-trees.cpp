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

    bool helper(TreeNode *root1, TreeNode *root2){

        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1->val != root2->val) return false;

        bool left = helper(root1->left,root2->left) || helper(root1->left,root2->right);
        bool right = helper(root1->right,root2->right) || helper(root1->right,root2->left);
        return left && right;

    }

    int countnodes(TreeNode *root){

        if(root == NULL) return 0;
        return countnodes(root->left)+countnodes(root->right)+1;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        int count1 = countnodes(root1);
        int count2 = countnodes(root2);
        if(count1 != count2) return false;
        return helper(root1,root2);

    }
};