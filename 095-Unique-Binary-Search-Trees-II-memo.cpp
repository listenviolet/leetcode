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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        vector<vector<vector<TreeNode*> > > memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
    
    vector<TreeNode*> helper(int start, int end, vector<vector<vector<TreeNode*>>>& memo)
    {
        if(start > end) return {nullptr};
        if(!memo[start - 1][end - 1].empty()) return memo[start - 1][end - 1];
        vector<TreeNode*> res;
        
        for(int i = start; i <= end; ++i)
        {
            auto left = helper(start, i - 1, memo), right = helper(i + 1, end, memo);
            for(auto a : left)
            {
                for(auto b: right)
                {
                    TreeNode *node = new TreeNode(i);
                    node -> left = a;
                    node -> right = b;
                    res.push_back(node);
                }
            }
        }
        return memo[start - 1][end - 1] = res;
    }
};

// Runtime: 12 ms, faster than 98.00% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 12.6 MB, less than 97.22% of C++ online submissions for Unique Binary Search Trees II.
// https://www.cnblogs.com/grandyang/p/4301096.html
// Dynamic Programming，其实带记忆数组的递归形式就是 DP 的一种，
// memo[i][j] 表示在区间 [i, j] 范围内可以生成的所有 BST 的根结点，
// 所以 memo 必须是一个三维数组，这样在递归函数中，我们就可以去 memo 中查找当前的区间是否已经计算过了，
// 是的话，直接返回 memo 中的数组，否则就按之前的方法去计算，最后计算好了之后要更新 memo 数组，