// Lowest Common Ancestor of a Binary Search Tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) {
            return NULL;
        }
        if(root -> val == p -> val || root -> val == q -> val){
            return root;
        }
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        if(left != NULL && right != NULL) {
            return root;
        }
        if(left != NULL){
            return left;
        }
        if(right != NULL){
            return right;
        }
        return NULL;
    }
};
