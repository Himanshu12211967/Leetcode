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

    int countnodes(TreeNode *root){
        if(root == NULL) return 0;
        return countnodes(root->left)+countnodes(root->right)+1;
    }

    bool helper(TreeNode *root, int node_no, int &total_nodes){

        if(root == NULL) return true;
        if(node_no > total_nodes) return false;

        return helper(root->left,2*node_no,total_nodes) && helper(root->right,2*node_no+1,total_nodes);

    }

    bool isCompleteTree(TreeNode* root) {
        
        int total_nodes = countnodes(root);
        return helper(root,1,total_nodes);

    }
};