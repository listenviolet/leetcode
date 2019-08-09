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
        if (n == 0) return {};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1), right = helper(i + 1, end);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};

// https://www.cnblogs.com/grandyang/p/4301096.html
// 用递归来解，划分左右两个子数组，递归构造。
// 刚开始时，我们将区间 [1, n] 当作一个整体，然后我们需要将其中的每个数字都当作根结点，
// 其划分开了左右两个子区间，然后分别调用递归函数，会得到两个结点数组，
// 接下来要做的就是从这两个数组中每次各取一个结点，当作当前根结点的左右子结点，
// 然后将根结点加入结果 res 数组中即可
// res stores the roots of (sub)trees. so each root node indicates a tree.


// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3