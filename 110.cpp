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
    // Method 1:
    /*bool isBalanced(TreeNode *root) {
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
    }*/
    // Method 2:
    int dfsHeight (TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight (root) != -1;
    }
};
