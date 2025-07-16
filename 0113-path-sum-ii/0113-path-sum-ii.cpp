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

    void helper(vector<vector<int>> &ans,TreeNode* root, int targetSum, vector<int> temp){

        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(root->val);
        helper(ans,root->left,targetSum-root->val,temp);
        helper(ans,root->right,targetSum-root->val,temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,root,targetSum,temp);
        return ans;
    }
};