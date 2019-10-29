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
    int rob(TreeNode* root) {
        return robRec(root).first;
    }
    
    pair<int,int> robRec(TreeNode* root) {
        if (!root) return {0,0};
        pair<int,int> right = robRec(root->right);
        pair<int,int> left  = robRec(root->left);
        return {max(root->val + right.second + left.second, left.first + right.first), right.first + left.first};
    }
};
