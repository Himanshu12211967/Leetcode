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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *ans = NULL;
        ListNode *temp = NULL;

        while(list1 != NULL && list2 != NULL){

            if(list1->val < list2->val){
                if(ans == NULL) ans = list1;
                else temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                if(ans == NULL) ans = list2;
                else temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }

        }

        
        while(list2 != NULL){
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
        
        while(list1 != NULL){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }

        return ans;
        

    }
};