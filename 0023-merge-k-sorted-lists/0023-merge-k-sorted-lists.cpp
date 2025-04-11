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
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
            pq.push({lists[i]->val,lists[i]});
        }

        ListNode *temp = NULL;
        ListNode *ans = NULL;

        while(!pq.empty()){

            ListNode* node = pq.top().second;
            pq.pop();

            if(ans == NULL){
                temp = node;
                ans = node;
            }
            else{
                temp->next = node;
                temp = node;
            }

            if(node->next != NULL) pq.push({node->next->val,node->next});

        }

        return ans;

    }
};