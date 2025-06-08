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

    ListNode *reverse(ListNode *head){

        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode *ans = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){

            int a = 0,b = 0;

            if(l1 != NULL){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                b = l2->val;
                l2 = l2->next;
            }

            int sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;

            ListNode *newnode = new ListNode(sum);
            if(ans == NULL) ans = newnode;
            else{
                newnode->next = ans;
                ans = newnode;
            }

        }

        ans = reverse(ans);
        return ans;
        
    }
};