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
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }

    bool fun(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return 1;
        if(l==NULL || r==NULL) return 0;

        bool lb = fun(l->left,r->right);
        bool rb = fun(l->right,r->left);
        bool value = l->val==r->val;
        
        return (lb && rb && value);
    }
};
