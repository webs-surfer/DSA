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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if (!root)
            return ans;
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int vd = temp.second.second;
            node[hd][vd].push_back(frontNode->val);
            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, vd + 1)));
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, vd + 1)));
        }
        for (auto& i : node) {
            vector<int> col;
            for (auto& j : i.second) {
                sort(j.second.begin(), j.second.end());
                for (int x : j.second)
                    col.push_back(x);
            }
            ans.push_back(col);
        }
        return ans;
    }
};