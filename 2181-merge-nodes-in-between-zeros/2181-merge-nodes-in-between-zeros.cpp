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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* nextSum = modify;

        while (nextSum != nullptr) {
            int sum = 0;
            while (nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }

            modify->val = sum;
            nextSum = nextSum->next;
            modify->next = nextSum;
            modify = modify->next;
        }
        return head->next;
    }
};