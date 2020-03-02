/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);
        ListNode more_head(0);
        ListNode* less_Ptr =  &less_head;
        ListNode* more_Ptr = &more_head;
        while(head){
            if(head->val < x){
                less_Ptr->next = head;
                less_Ptr = head;
            }
            else{
                more_Ptr->next = head;
                more_Ptr = head;
            }
            head = head->next;
        }
        less_Ptr->next = more_head.next;
        more_Ptr->next = NULL;
        return less_head.next;
        
    }
};