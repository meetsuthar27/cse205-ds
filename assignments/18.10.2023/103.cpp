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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (!root) {
            return ans; 
        }

        
        q.push(root);
        bool zigzag = false; 

        while (!q.empty()) {
            int k = q.size();
            vector<int>levels(k);

            for (int i =0;i< k;i++) {
                TreeNode* node = q.front();
                q.pop();

                if (!zigzag) {
                    levels[i] = node->val; 
                } else {
                    levels[k-1-i] = node->val; 
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            zigzag = !zigzag; 
            ans.push_back(levels);
        }

        return ans;
    }
};
