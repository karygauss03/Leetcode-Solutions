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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a=NULL,*b=NULL,*t=head;
        while(t){
            if(b&&b->next)b=b->next;
            if(--k==0){
                a=t;
                b=head;
            }
            t=t->next;
        }
        swap(a->val,b->val);
        
        return head;
    }
};