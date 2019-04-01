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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
        {
            return true;
        }
        
        vector<int> new_list;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            new_list.insert(new_list.begin(), slow->val);
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if(fast != NULL)
        {
            slow = slow -> next;
        }
        
        for(int i = 0; i < new_list.size(); ++i)
        {
            if(new_list[i] != slow -> val)
            {
                return false;
            }
            slow = slow -> next;
        }
        return true;
    }
};

// Description:
// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

// Runtime: 356ms
// Beats: 5.34%
// Memory beats: 34.32%