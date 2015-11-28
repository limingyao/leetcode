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
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        while(p != NULL) {
            s.push(p);
            p = p->left;
        }
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
        int ret = p -> val;
        if(p -> right != NULL) {
            p = p -> right;
            while(p != NULL) {
                s.push(p);
                p = p->left;
            }
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
