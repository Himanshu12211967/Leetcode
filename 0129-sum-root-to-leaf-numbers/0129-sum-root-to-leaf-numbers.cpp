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

    int solve(TreeNode *root,int num){

        if(!root) return 0;
        if(root->left == NULL && root->right == NULL){
            num = num*10 + root->val;
            return num;
        }

        int total = 0;
        num = num*10 + root->val;

        total += solve(root->left,num);
        total += solve(root->right,num);
        return total;

    }

    int sumNumbers(TreeNode* root) {
        
        return solve(root,0);

    }
};