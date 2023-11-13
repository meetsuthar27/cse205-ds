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
    TreeNode* find(TreeNode* curr)
    {
        TreeNode* temp = curr;
        temp = temp -> left;
        while(temp ->right != NULL && temp->right !=curr)
        {
            temp = temp->right;
        }

        return temp;
    }

    void morrisTraversal(TreeNode* root, vector<int> &ans)
    {
        TreeNode* curr = root;

        while(curr!= NULL)
        {
            if(curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* pred = find(curr);

                if(pred -> right == NULL)
                {
                    pred ->right = curr;
                    curr = curr -> left;
                }
                else
                {
                    pred -> right = NULL;
                    ans.push_back(curr->val);
                    curr = curr -> right;
                }
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        vector<int> ans;

        morrisTraversal(root,ans);
        return ans[k-1];
    }
};
