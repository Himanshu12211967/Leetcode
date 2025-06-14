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

    void update(TreeNode *root,TreeNode *&first,TreeNode *&second){

        if(first == NULL){
            first = root;
            return;
        }
        if(second == NULL){
            second = root;
            return;
        }

    }

    void traverse(TreeNode* root,vector<int> &v){

        if(root == NULL) return;

        v.push_back(root->val);
        traverse(root->left,v);
        traverse(root->right,v);

    }

    int getMinimumDifference(TreeNode* root) {

        vector<int> v;
        traverse(root,v);
        int ans = INT_MAX;

        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                ans = min(ans,abs(v[i]-v[j]));
            }
        }


        return ans;
    }
};