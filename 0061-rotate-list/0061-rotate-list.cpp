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
            head=head->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) return NULL;
        int len = count(head);
        k = k % len;
        if(k == 0) return head;
        k = len-k;

        ListNode *ans = NULL;
        ListNode *temp = head;

        while(temp->next != NULL){
            temp=temp->next;
            k--;
            if(k == 0) ans = temp;
        }

        temp->next = head;

        while(head != NULL && head->next != ans){
            head=head->next;
        }

        head->next = NULL;
        return ans;
    }
};