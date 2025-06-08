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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || head->next == NULL) return head;

        ListNode *temp = head;
        ListNode *ans = NULL;
        ListNode *prev = NULL;

        while(temp != NULL){

            if(temp->next == NULL){
                if(ans == NULL) ans = temp;
                return ans;
            }
            else if(temp->val != temp->next->val){
                if(ans == NULL) ans = temp;
                prev = temp;
                temp = temp->next;
            }
            else{
                ListNode *t = temp->next;
                while(t != NULL && t->val == temp->val){
                    ListNode *todelete = t;
                    t = t->next;
                    delete(todelete);
                }

                if(prev != NULL) prev->next = t;
                delete(temp);
                temp = t;
            }
        }

        return ans;

    }
};