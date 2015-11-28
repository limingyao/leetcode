// Binary Search Tree Iterator

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
    void push_left_all(TreeNode *root) {
        while(root != NULL) {
            s.push(root);
            root = root -> left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        push_left_all(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(!hasNext()) return NULL;
        TreeNode *p = s.top();
        s.pop();
        push_left_all(p -> right);
        return p -> val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
