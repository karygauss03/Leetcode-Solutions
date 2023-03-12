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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(); // taking size of the list
        if(k == 0) // if size is zero
            return NULL; // simply return NULL
        
        // making a vector pair where first contain value and second contain node
        vector<pair<int, ListNode*>> arr; 
        
        for(int i = 0; i < k; i++) // traverse all over the list
        {
            ListNode* curr_list = lists[i]; // extracting current linked list
            
            while(curr_list != NULL) // while current linked list is NOT NULL
            {
                arr.push_back({curr_list -> val, curr_list}); // push into vector
                curr_list = curr_list -> next;
            }
        }
        
        // this does not gurantee that k is zero, 
        // suppose an array like this [[],[],[],],here k = 3 and size of array is 0
        if(arr.size() == 0) // if their is no element i.e zero element
            return NULL;
        
        sort(arr.begin(), arr.end()); // sort the vector on the basis of values
        
        // start making links b/w the elements of vector
        for(int i = 0; i < arr.size() - 1; i++)
        {
            arr[i].second -> next = arr[i + 1].second;
        }
        
        // in the next of last node put NULL
        arr[arr.size() - 1].second -> next = NULL;
        
        return arr[0].second; // return first node of the vector
    }
};