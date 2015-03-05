// Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        if(root!=NULL){
            s.push(root);
        }
        while(!s.empty()){
            TreeNode *cur = s.top();
            if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(pre==cur->left||pre==cur->right))){
                ans.push_back(cur->val);
                s.pop();
                pre = cur;
            }else{
                if(cur->right!=NULL){
                    s.push(cur->right);
                }
                if(cur->left!=NULL){
                    s.push(cur->left);
                }
            }
        }
        return ans;
    }
};

// 后序遍历 → <左右根>
// 是否可以<根右左>遍历，再把结果逆序一下，既是后序遍历的结果？
