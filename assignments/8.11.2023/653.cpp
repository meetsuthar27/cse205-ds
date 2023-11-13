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
class BSTIterator {

private: 
    stack<TreeNode*> st;
    bool reverse = false;

public:

    int next() {
        TreeNode* temp = st.top();
        int elem = st.top()->val;
        st.pop();
        if(reverse) pushAll(temp -> left);
        else pushAll(temp -> right);
        
        return elem;
    }
    
    bool hasNext() {
        return !st.empty();
    }

        BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
private:
    void pushAll(TreeNode* root)
    {
        for(; root!=NULL;)
        {
            st.push(root);
            if(reverse)
                root = root -> right;
            else root = root -> left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root) return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j)
        {
            if(k == i+j) return true;
            else if(k > i + j) i = l.next();
            else j = r.next();
        }

        return false;
    }
};
