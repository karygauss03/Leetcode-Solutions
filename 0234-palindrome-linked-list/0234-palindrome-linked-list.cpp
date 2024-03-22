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
    ListNode* middleNode (ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; //this is the middle node
    }
    
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while (cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev; //this is the reversed linked list
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return true;
        }
        ListNode* mid;
        ListNode* rev;
        mid = middleNode(head);
        rev = reverseLinkedList(mid->next);
        mid->next = NULL;
        ListNode* a = head;
        ListNode* b = rev;
        while (a != NULL && b != NULL){
            if (a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }
    
};