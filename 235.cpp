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

// Method 2:
// 充分利用sbt输的性质
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
        while(root!=NULL && ((root -> val - p -> val) * (root -> val - q -> val) > 0)) {
            if(p -> val < root -> val) {
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
        return root;
    }
};
