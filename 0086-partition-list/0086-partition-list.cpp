/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* partition(ListNode* head, int x) {
        
        ListNode *root = NULL;
        ListNode *firstListconn = NULL;
        ListNode *second_root = NULL;
        ListNode *secondListconn = NULL;

        while(head != NULL){

            if(head->val < x){
                if(root == NULL){
                    root = head;
                    firstListconn = head;
                }
                else{
                    firstListconn->next = head;
                    firstListconn = head;
                }
            }
            else{
                if(second_root == NULL){
                    second_root = head;
                    secondListconn = head;
                }
                else{
                    secondListconn->next = head;
                    secondListconn = head;
                }
            }

            head = head->next;
        }

        if(root == NULL) return second_root;
        if(second_root == NULL) return root;
        firstListconn->next = second_root;
        secondListconn->next = NULL;
        return root;

    }

    
};