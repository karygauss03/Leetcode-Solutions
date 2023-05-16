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
        if (!head || !head->next){
            return head;
        }
        
        ListNode* tmp = new ListNode();
        ListNode* cur = head;
        ListNode* prev = tmp;
        
        while (cur && cur->next){
            prev->next = cur->next;
            cur->next = prev->next->next;
            prev->next->next = cur;
            
            prev = cur;
            cur = cur->next;
        }
        return tmp->next;
    }
};