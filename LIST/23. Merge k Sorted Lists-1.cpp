/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <algorithm>
bool cmp(const ListNode *a, const ListNode *b){
    return a -> val < b -> val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode*> ListNode_vec;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head){
                ListNode_vec.push_back(head);
                head = head -> next;
            }
            
        }
        if(ListNode_vec.size() == 0){
            return NULL;
        }
        std::sort(ListNode_vec.begin(), ListNode_vec.end(), cmp);
        for(int i =1; i < ListNode_vec.size(); i++){
            ListNode_vec[i - 1] -> next = ListNode_vec[i];
        }
        ListNode_vec.back() -> next = NULL;
        return ListNode_vec[0];
    }
};