// Binary Tree Paths

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
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ret;
            if(root==NULL) {
                return ret;
            }
            vector<string> left = binaryTreePaths(root->left);
            for(int i=0;i<left.size();i++) {
                ret.push_back(int2string(root->val)+"->"+left[i]);
            }
            vector<string> right = binaryTreePaths(root->right);
            for(int i=0;i<right.size();i++) {
                ret.push_back(int2string(root->val)+"->"+right[i]);
            }
            if(left.size()<1 && right.size()<1){
                ret.push_back(int2string(root->val));
            }
            return ret;
        }
    private:
        string int2string(int val){
            char buf[256];
            // itoa(val,buf,10);
            sprintf(buf,"%d",val);
            string ret(buf);
            return ret;
        }
};
