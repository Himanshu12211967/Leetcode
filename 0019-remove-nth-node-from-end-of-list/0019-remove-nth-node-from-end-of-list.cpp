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

    int count(ListNode *head){

        int len = 0;

        while(head){
            head = head->next;
            len++;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *temp = head;
        int len = count(head);
        int k = len - n;

        // if len == n
        if(n == len){
            ListNode *todelete = head;
            head = head->next;
            delete(todelete);
            return head;
        }

        while(temp != NULL && k != 1){
            temp = temp->next;
            k--;
        }

        ListNode *todelete = temp->next;
        temp->next = temp->next->next;
        delete(todelete);
        return head;

    }
};