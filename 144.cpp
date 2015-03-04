// Binary Tree Preorder Traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        // Method 1:
        /*if(root!=NULL){
            s.push(root);
        }
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            ans.push_back(p->val);
            
            if(p->right!=NULL){
                s.push(p->right);
            }
            if(p->left!=NULL){
                s.push(p->left);
            }
        }*/
        // Method 2:
        TreeNode *p = root;
        while(p!=NULL||!s.empty()){
            while(p!=NULL){
                ans.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if(!s.empty()){
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
