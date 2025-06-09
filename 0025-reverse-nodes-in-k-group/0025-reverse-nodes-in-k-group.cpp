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

    ListNode *reverse(ListNode *&curr,int k){

        ListNode *prev = NULL;
        ListNode *next = NULL;

        while(curr != NULL && k != 0){
            next = curr->next;
            curr->next =  prev;
            prev = curr;
            curr = next;
            k--;
        }

        return prev;
    }

    int count(ListNode *head){
        int len = 0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *ans = NULL;
        ListNode *temp = NULL;

        int len = count(head);

        while(head != NULL && len >= k){
            ListNode *sub_list = reverse(head,k);
            len -= k;
            if(ans == NULL){
                temp = sub_list;
                ans = sub_list;
                continue;
            }
            while(temp->next != NULL) temp=temp->next;
            temp->next = sub_list;

        }

        while(temp->next != NULL) temp=temp->next;
        temp->next = head;
        return ans;
    }
};