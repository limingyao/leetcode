// Binary Tree Level Order Traversal

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        queue<TreeNode *> subq;
        vector<vector<int> > ans;
        vector<int> subans;
        
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()||!subq.empty()){
            TreeNode *p = q.front();
            if(p->left!=NULL){
                subq.push(p->left);
            }
            if(p->right!=NULL){
                subq.push(p->right);
            }
            subans.push_back(p->val);
            q.pop();
            if(q.empty()){
                ans.push_back(subans);
                while(!subq.empty()){
                    q.push(subq.front());
                    subq.pop();
                }
                subans.clear();
            }
        }
        return ans;
    }
};
