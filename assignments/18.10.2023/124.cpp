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
    int maxi=INT_MIN;

    int maxPathSum(TreeNode* root) {
        maxx(root);
        
        return maxi;
    }

    int maxx(TreeNode* root){
        if(!root){
            return 0;}

        int left=max(maxx(root->left),0);
        int right=max(maxx(root->right),0);

        int new_price =root->val+left+right;

        maxi= max(maxi, new_price);
        return root->val+max(left,right);
    }
};
