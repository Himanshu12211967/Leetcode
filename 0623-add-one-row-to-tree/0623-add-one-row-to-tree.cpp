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

    TreeNode *solve(TreeNode *root, int val, int depth, int curr_depth){

        if(root == NULL) return NULL;

        if(curr_depth+1 == depth){
            TreeNode *newnode1 = new TreeNode(val);
            TreeNode *newnode2 = new TreeNode(val);
            newnode1->left = root->left;
            newnode2->right = root->right;
            root->left = newnode1;
            root->right = newnode2;
            return root;
        }

        root->left = solve(root->left,val,depth,curr_depth+1);
        root->right = solve(root->right,val,depth,curr_depth+1);
        return root;

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1){
            TreeNode *newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }

        return solve(root,val,depth,1);
    }
};