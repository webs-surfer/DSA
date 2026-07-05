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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* curr = head;
        int count = 0;
        while(curr!= NULL && count<2){
            curr = curr->next;
            count++;
        }
        if(count==2){
            ListNode* next = NULL;
            ListNode* curr = head;
            ListNode* prev = NULL;
            for(int i=0; i<2; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head->next = swapPairs(next);
            return prev;
        }
        return head;
    }
};