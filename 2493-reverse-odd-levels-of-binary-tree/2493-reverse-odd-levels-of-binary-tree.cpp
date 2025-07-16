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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root == NULL) return NULL;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            int lvl;
            vector<TreeNode*> temp;

            while(size--){

                TreeNode *node = q.front().first;
                lvl = q.front().second;
                q.pop();
                temp.push_back(node);

                if(node->left) q.push({node->left,lvl+1});
                if(node->right) q.push({node->right,lvl+1});
            }

            if(lvl % 2 != 0){
                int st = 0, end = temp.size()-1;
                while(st < end){
                    swap(temp[st++]->val,temp[end--]->val);
                }
            }

        }

        return root;

    }
};