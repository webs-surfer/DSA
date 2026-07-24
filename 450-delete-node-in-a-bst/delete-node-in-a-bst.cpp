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
    void solve(TreeNode* curr, TreeNode* prev) {
        if (!curr->left && !curr->right) {

            if (prev->left == curr) {
                prev->left = NULL;
            } else {
                prev->right = NULL;
            }

        } else if ((!curr->left && curr->right) ||
                   (!curr->right && curr->left)) {
            if (curr->left) {
                if (prev->left == curr) {
                    prev->left = curr->left;
                } else {
                    prev->right = curr->left;
                }

            } else {
                if (prev->left == curr) {
                    prev->left = curr->right;
                } else {
                    prev->right = curr->right;
                }
            }
        } else {
            TreeNode* parent = curr;
            TreeNode* newNode = curr->left;

            while (newNode->right) {
                parent = newNode;
                newNode = newNode->right;
            }

            curr->val = newNode->val;
            solve(newNode, parent);
        }
    }
    TreeNode* handleRoot(TreeNode* root) {
        if (!root->left && !root->right)
            return NULL;

        if (root->left && !root->right)
            return root->left;

        if (!root->left && root->right)
            return root->right;

        TreeNode* parent = root;
        TreeNode* pred = root->left;

        while (pred->right) {
            parent = pred;
            pred = pred->right;
        }

        root->val = pred->val;
        solve(pred, parent);

        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root || (!root->left && !root->right && root->val == key))
            return NULL;

        TreeNode* prev = NULL;
        TreeNode* curr = root;
        while (curr && curr->val != key) {
            prev = curr;
            if (curr->val < key) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        if (!curr)
            return root;
        if (curr == root) {
            TreeNode* newRoot = handleRoot(root);
            return newRoot;
        } else {
            solve(curr, prev);
        }
        return root;
    }
};