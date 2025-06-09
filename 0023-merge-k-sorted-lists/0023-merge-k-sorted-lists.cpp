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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *ans = NULL;
        ListNode *temp = NULL;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
            pq.push({lists[i]->val,lists[i]});
        }

        while(!pq.empty()){

            ListNode *top = pq.top().second;
            pq.pop();

            if(ans == NULL){
                temp = top;
                ans = top;
            }
            else{
                temp->next = top;
                temp = top;
            }

            if(top->next != NULL) pq.push({top->next->val,top->next});

        }

        return ans;
        
    }
};