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

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return head;
        ListNode *newhead = head;
        ListNode *tail = NULL;
        int len = 0;

        for(ListNode *temp = head; temp != NULL; temp=temp->next){
            len++;
            if(temp->next == NULL) tail = temp; // update the tail node
        }

        if(k == 0 || k % len == 0) return head;

        k = k % len;
        k = len - k;
        while(k != 0){
            newhead = newhead->next;
            k--;
        }

        tail->next = head;

        while(head->next != newhead){
            head = head->next;
        }     

        head->next = NULL;
        return newhead;

    }
};