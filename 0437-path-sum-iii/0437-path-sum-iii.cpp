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

    int ans = 0;

    void helper(TreeNode* root, int targetSum, vector<int> temp){

        if(root == NULL) return;
        temp.push_back(root->val);

        long long int sum = 0;
        for(int i=temp.size()-1; i>=0; i--){
            sum += temp[i];
            if(sum == targetSum) ans++;
        }

        helper(root->left,targetSum,temp);
        helper(root->right,targetSum,temp);
        temp.pop_back();

    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root,targetSum,temp);
        return ans;
    }
};