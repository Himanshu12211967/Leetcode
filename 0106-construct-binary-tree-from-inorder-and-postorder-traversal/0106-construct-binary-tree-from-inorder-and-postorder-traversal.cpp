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

    int find(vector<int> &inorder,int val){

        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == val) return i;
        }
        return -1;

    }

    TreeNode *solve(vector<int>& postorder, vector<int>& inorder,int &index,int st,int end){

        if(st > end) return NULL;
        int val = postorder[index--];
        TreeNode *root = new TreeNode(val);
        int find_index = find(inorder,val);
        root->right = solve(postorder,inorder,index,find_index+1,end);
        root->left = solve(postorder,inorder,index,st,find_index-1);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        return solve(postorder,inorder,index,0,postorder.size()-1);
    }
};