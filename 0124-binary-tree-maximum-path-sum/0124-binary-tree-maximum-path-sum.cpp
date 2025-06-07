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

    int max_path_sum = INT_MIN;

    int solve(TreeNode *root){

        if(root == NULL) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int case1 = root->val+left;
        int case2 = root->val+right;

        max_path_sum = max({max_path_sum,case1,case2,root->val+left+right,root->val});
        return max({case1,case2,root->val});

    }

    int maxPathSum(TreeNode* root) {
        
        solve(root);
        return max_path_sum;

    }
};