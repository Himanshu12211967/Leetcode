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

            while(size--){

                TreeNode *node = q.front().first;
                int lvl = q.front().second;
                q.pop();

                int next_lvl_sum = (lvl+1 < lvl_sum.size()) ? lvl_sum[lvl+1] : 0;
                int sibling_sum = 0;

                if(node->left) sibling_sum += node->left->val;
                if(node->right) sibling_sum += node->right->val;

                int cousins_sum = next_lvl_sum - sibling_sum;

                if(node->left){
                    q.push({node->left,lvl+1});
                    node->left->val = cousins_sum;
                }

                if(node->right){
                    q.push({node->right,lvl+1});
                    node->right->val = cousins_sum;
                }

            }

        }

        return root;

    }
};