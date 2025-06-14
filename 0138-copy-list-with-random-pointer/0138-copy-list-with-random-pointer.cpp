/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node *copyhead = NULL;
    Node *copytail = NULL;

    void insert(Node *temp){

        if(copyhead == NULL){
            copyhead = temp;
            copytail = temp;
            return;
        }

        copytail->next = temp;
        copytail = temp;
        
    }

    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*> m;
        Node *temp = head;

        while(temp != NULL){
            Node *newnode = new Node(temp->val);
            m[temp] = newnode;
            insert(newnode);
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            m[temp]->random = m[temp->random];
            temp=temp->next;
        }

        return copyhead;
    }
};