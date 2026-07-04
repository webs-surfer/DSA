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
private:
    ListNode* solve(ListNode* first, ListNode* second){
        ListNode* curr1 = first;
        ListNode* next1 = first->next;
        ListNode* curr2 = second;
        ListNode* next2 = NULL;
        if(next1==NULL){
            curr1->next = curr2;
            return first;
        }
        while(next1 != NULL && curr2 != NULL){
            if((curr2->val >= curr1->val) && (curr2->val <= next1->val)){
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                //update pointer
                curr1 = curr2;
                curr2 = next2;
                next1 = curr1->next;
            }
            else{
                curr1 = next1;
                next1 = next1->next;
                
                if(next1==NULL){
                    curr1->next = curr2;
                    return first;
                }
             
            }
        }
        return first;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val <= list2->val){
            return solve(list1,list2);
        }else{
            return solve(list2,list1);
        }
    }
};