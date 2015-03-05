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

// 是不是可以不需要两个队列，而是使用一个计数器？

// 充分利用vector
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ans;
        if (!root) return ans;
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            int i = q.front().second;
            TreeNode * node = q.front().first;
            if (ans.size() >= i) ans.resize(i + 1);
            ans[i].push_back(node -> val);
            if (node -> left) q.push(make_pair(node -> left, i + 1));
            if (node -> right) q.push(make_pair(node -> right, i + 1));
            q.pop();
        }
        return ans;
    }

};
