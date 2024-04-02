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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *f=list1,*s=list1;
        for(int i=0;i<a-1;i++) f=f->next;
        
        for(int i=0;i<b;i++) s=s->next;
        
        f->next=list2;
        while(list2->next!=NULL)
            list2=list2->next;
        
        list2->next=s->next;
        return list1;
    }
};