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
        auto cmp = [](ListNode *&a, ListNode *&b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for(auto node: lists)
        {
            if(node) q.push(node);
        }
        
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            cur -> next = t;
            cur = cur -> next;
            if(cur -> next) q.push(cur -> next);
        }
        return dummy -> next;
    }
};

// auto: 可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型，
// 类似的关键字还有decltype。
// Runtime: 40ms
// Beats: 47.40%
// Memory beats: 99.63%
// Time complexity: O(nlogk)
// Space complexity: O(n) -> create a new list
//                   O(k) -> in-place method cost O(1)
//                   O(k) -> priority_queue