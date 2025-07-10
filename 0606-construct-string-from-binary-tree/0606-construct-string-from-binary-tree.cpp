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

    void solve(TreeNode *root, string &str){

        if(root == NULL) return;

        string ch = to_string(root->val);
        str += ch;

        if(root->left || root->right){
            str.push_back('(');
            solve(root->left,str);
            str.push_back(')');
        }
        if(root->right){
            str.push_back('(');
            solve(root->right,str);
            str.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string str = "";
        solve(root,str);
        return str;
    }
};