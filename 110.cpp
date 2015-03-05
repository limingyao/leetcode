// Balanced Binary Tree

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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, &depth); 
    }
    bool isBalanced(TreeNode *root, int *depth) {
        if(root==NULL){
            *depth = 0;
            return true;
        }
        int leftDepth,rigthDepth;
        if(isBalanced(root->left, &leftDepth)&&isBalanced(root->right, &rigthDepth)){
            int diff = abs(leftDepth - rigthDepth);
            if(diff<=1){
                *depth = 1 + max(leftDepth,rigthDepth);
                return true;
            }
            
        }
        return false;
    }
};
