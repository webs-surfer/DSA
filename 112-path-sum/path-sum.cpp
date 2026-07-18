/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans=-1;
    void updateSum(TreeNode* root, int targetSum) {
        if(!root || ans==0)return;
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                ans = 0;
            }
            return;
        }
        updateSum(root->left, targetSum - root->val);
        updateSum(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        updateSum(root, targetSum);
        return ans == 0;
    }
};