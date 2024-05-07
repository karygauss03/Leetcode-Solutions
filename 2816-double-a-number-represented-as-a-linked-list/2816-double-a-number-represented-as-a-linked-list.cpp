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
    int multiply(ListNode* head){
        if(!head) return 0;
        int t = head->val*2 + multiply(head->next);
        head->val = t%10;
        return t/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int t = multiply(head);
        if(t) head = new ListNode(t, head);
        return head;
    }
};