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

    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<int> lvl_sum;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            int sum = 0;

            while(size--){

                TreeNode *node = q.front().first;
                int lvl = q.front().second;
                q.pop();

                sum += node->val;

                if(node->left){
                    q.push({node->left,lvl+1});
                }

                if(node->right){
                    q.push({node->right,lvl+1});
                }

            }

            lvl_sum.push_back(sum);

        }

        root->val = 0;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            int sum = 0;

            while(size--){

                TreeNode *node = q.front().first;
                int lvl = q.front().second;
                q.pop();

                int total_sum = 0;
                if(lvl+1 < lvl_sum.size())
                total_sum = lvl_sum[lvl+1];

                if(node->left){
                    q.push({node->left,lvl+1});
                    total_sum -= node->left->val;
                }

                if(node->right){
                    q.push({node->right,lvl+1});
                    total_sum -= node->right->val;
                }

                if(node->left){
                    node->left->val = total_sum;
                }

                if(node->right){
                    node->right->val = total_sum;
                }

            }

        }

        return root;

    }
};