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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;
        auto odd = head, even = head -> next, evenHead = even;
        while(even && even -> next) {
            odd = odd -> next = even -> next;
            even = even -> next = odd -> next;
        }
        odd -> next = evenHead;
        return head;
    }
};