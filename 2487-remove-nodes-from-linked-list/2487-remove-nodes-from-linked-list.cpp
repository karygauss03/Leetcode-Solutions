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
class Solution 
{
public:
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode* dummy = new ListNode(INT_MAX);
        vector<ListNode*> stack = {dummy};
        
        while (head)
        {
            while (!stack.empty() && head->val > stack.back()->val)
                stack.pop_back();
            stack.back()->next = head;
            stack.push_back(head);
            head = head->next;
        }
        
        return dummy->next;
    }
};