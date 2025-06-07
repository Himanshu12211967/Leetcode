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

    int index = 0;

    int find(vector<int> &inorder,int val){

        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == val) return i;
        }
        return -1;

    }

    TreeNode *solve(vector<int>& preorder, vector<int>& inorder,int st,int end){

        if(st > end) return NULL;
        int val = preorder[index++];
        TreeNode *root = new TreeNode(val);
        int find_index = find(inorder,val);
        root->left = solve(preorder,inorder,st,find_index-1);
        root->right = solve(preorder,inorder,find_index+1,end);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};