/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        int amount = lists.size();
        int interval = 1;
        while(interval < amount)
        {
            for(int i = 0; i < amount - interval; i += (2 * interval))
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            
            interval *= 2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode *&l1, ListNode *&l2)
    {
        ListNode *root = new ListNode(0);
        ListNode *p = root;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val < l2 -> val)
            {
                p -> next = l1;
                l1 = l1 -> next;
            }
            
            else
            {
                p -> next = l2;
                l2 = l2 -> next;
            }
            
            p = p -> next;
        }
        
        if(l1 != NULL) p -> next = l1;
        else p -> next = l2;
        return root -> next;
    }
};

// Runtime: 24 ms, faster than 90.61% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.2 MB, less than 63.09% of C++ online submissions for Merge k Sorted Lists.

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
