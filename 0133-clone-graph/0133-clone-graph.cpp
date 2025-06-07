/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void solve(Node *&node,Node *&head,map<Node*,Node*> &visited){

        visited[node] = head;
        for(auto x : node->neighbors){
            if(visited.find(x) != visited.end()){
                head->neighbors.push_back(visited[x]);
                continue;
            }
            Node *newnode = new Node(x->val);
            head->neighbors.push_back(newnode);
            solve(x,newnode,visited);
        }
    }

    Node* cloneGraph(Node* node) {
        
        if(!node) return NULL;
        Node *head = new Node(node->val);

        map<Node*,Node*> visited;
        solve(node,head,visited);
        return head;

    }
};