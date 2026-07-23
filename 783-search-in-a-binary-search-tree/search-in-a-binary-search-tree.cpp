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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* ans = NULL;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val==val){
                ans = temp;
                break;
            }
            if(temp->left && temp->val>val){
                q.push(temp->left);
            }
            if(temp->right && temp->val<val)
                q.push(temp->right);
            }
        return ans;
    }
};