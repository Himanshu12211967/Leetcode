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

    void solve(vector<string> &ans,TreeNode *root,string temp){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        string ch = to_string(root->val);
        solve(ans,root->left,temp+ch+"->");
        solve(ans,root->right,temp+ch+"->");

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(ans,root,"");
        return ans;
    }
};