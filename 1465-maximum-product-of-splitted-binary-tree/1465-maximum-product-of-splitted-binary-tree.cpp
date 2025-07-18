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

    long long ans = 0;

    long long solve(TreeNode *root, long long total_sum){

        if(root == NULL) return 0; 

        long long left = solve(root->left,total_sum);
        long long right = solve(root->right,total_sum);
        
        long long c = total_sum - left - right - root->val;

        ans = max({ans,(left+right+root->val)*c});
        return left + right + root->val;
    }

    long long helper(TreeNode *root){

        if(root == NULL) return 0;
        return helper(root->left)+helper(root->right)+root->val;
    }

    int maxProduct(TreeNode* root) {
        
        long long total_sum = helper(root);
        solve(root,total_sum);
        return ans%1000000007;
    }
};