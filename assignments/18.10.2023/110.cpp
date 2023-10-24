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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        checkBalanse(root, ans);

        return ans;
    }


    int checkBalanse(TreeNode* root, bool& ans) {

        if (!root||!ans){
            return 0;}

        int lft = checkBalanse(root->left, ans);
        int rght = checkBalanse(root->right, ans);

        if (abs(lft - rght) > 1){
            ans = false;}
        
        return max(lft, rght) + 1;
    }
};
