/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre, *cur, *parent = nullptr, *first = nullptr, *second = nullptr;
        cur = root;
        while(cur)
        {
            if(cur -> left == NULL)
            {
                if(parent && parent -> val > cur -> val)
                {
                    if(first == NULL) first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur -> right;
            }
            
            else 
            {
                pre = cur -> left;
                while(pre -> right && pre -> right != cur) pre = pre -> right;
                if(pre -> right == NULL)
                {
                    pre -> right = cur;
                    cur = cur -> left;
                }
                
                else
                {
                    pre -> right = NULL;
                    if(parent -> val > cur -> val)
                    {
                        if(first == NULL) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur -> right;
                }
            }
        }
        
        swap(first -> val, second -> val);
    }
};

// Mirros traversal
// threaded tree
// https://www.cnblogs.com/grandyang/p/4298069.html
// Runtime: 36 ms, faster than 9.23% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 17.7 MB, less than 100.00% of C++ online submissions for Recover Binary Search Tree.