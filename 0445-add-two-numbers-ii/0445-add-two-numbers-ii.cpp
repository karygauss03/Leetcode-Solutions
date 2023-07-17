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
    ListNode* sum(ListNode* l1, ListNode* l2, int &car){
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        
        ListNode *node = new ListNode(-1);
        node->next = sum(l1->next, l2->next, car);
        
        node->val = (l1->val + l2->val + car) % 10;
        car = (l1->val + l2->val + car) / 10;
        
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *node1 = l1, *node2 = l2;
        ListNode *node;
        while (node1 != nullptr || node2 != nullptr) {
            if (node1 == nullptr) {
                node = new ListNode(0);
                node->next = l1;
                l1 = node;
                node2 = node2->next;
            }
            else if (node2 == nullptr) {
                node = new ListNode(0);
                node->next = l2;
                l2 = node;
                node1 = node1->next;
            }
            else {
                node1 = node1->next;
                node2 = node2->next;
            }
        }
        
        int car = 0;
        ListNode* tmp = new ListNode(-1);
        tmp->next = sum(l1, l2, car);
        if (car != 0) {
            node = new ListNode(car);
            node->next = tmp->next;
            tmp->next = node;
        }
        
        return tmp->next;
    }
};