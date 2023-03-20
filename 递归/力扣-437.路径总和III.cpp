/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPath(TreeNode* node, long long target) {
        if (node == nullptr)
            return 0;
        
        return (node->val == target) + countPath(node->left, target - node->val)
            + countPath(node->right, target - node->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;

        return countPath(root, targetSum) + pathSum(root->left, targetSum)
            + pathSum(root->right, targetSum);
    }
};
