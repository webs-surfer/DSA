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
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end, int n){
        if(index==n || start>end){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* temp = new TreeNode(element);
        int position = findpos(inorder,element,n);
        temp->left = solve(preorder,inorder,index,start,position-1,n);
        temp->right = solve(preorder,inorder,index,position+1,end,n);
        return temp;
    }
    int findpos(vector<int>& inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
        int n = preorder.size();
        TreeNode* ans = solve(preorder, inorder, preorderindex, 0 ,n-1,n);
        return ans;
    }
};