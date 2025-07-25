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

    bool helper(TreeNode* root, long long  mini, long long maxi){

        if(root == NULL) return true;
        if(root->val <= mini || root->val >= maxi) return false;

        bool left = helper(root->left,mini,root->val);
        bool right = helper(root->right,root->val,maxi);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        
        long long mini = LONG_MIN;
        long long maxi = LONG_MAX;
        return helper(root,mini,maxi);

    }
};