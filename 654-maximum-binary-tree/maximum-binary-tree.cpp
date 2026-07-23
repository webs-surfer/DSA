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
    void solve(vector<int>& nums,TreeNode* root,int s,int e,bool left){
        if(s>e)return;
        int maxIndex = max_element(nums.begin() + s, nums.begin() + e + 1) - nums.begin();
        TreeNode* temp = new TreeNode(nums[maxIndex]);
        if(left){
            root->left = temp;
        }else{
            root->right = temp;
        }
        solve(nums,temp,s,maxIndex-1,true);
        solve(nums,temp,maxIndex+1,e,false);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxIndex = max_element(nums.begin(),nums.end())-nums.begin();
        TreeNode* root = new TreeNode(nums[maxIndex]);
        solve(nums,root,0,maxIndex-1,true);
        solve(nums,root,maxIndex+1,nums.size()-1,false);
        return root;
    }
};