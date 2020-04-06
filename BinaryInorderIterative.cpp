/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root)
            return inorder;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()){
            while(s.top()){
                s.push(s.top()->left);
            }
            s.pop();
            if(!s.size())
                break;
            inorder.push_back(s.top()->val);
            TreeNode* temp=s.top();
            s.pop();
            s.push(temp->right);
        }
        return inorder;
    }
};