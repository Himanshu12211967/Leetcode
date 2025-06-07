/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return root;
        queue<pair<Node*,int>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();

            for(int i=0; i<size; i++){

                Node *node = q.front().first;
                int lvl = q.front().second;
                q.pop();

                if(!q.empty() && q.front().second == lvl) node->next = q.front().first;

                if(node->left) q.push({node->left,lvl+1});
                if(node->right) q.push({node->right,lvl+1});

            }

        }

        return root;

    }
};