/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkChild(root,LONG_MIN,LONG_MAX);
    }

//	递归方法
    bool checkChild(TreeNode* now,long long left,long long right)
    {
        if (!now) return 1;
        if (now->val <= left || now->val >= right) return 0;
        return checkChild(now->left,left,now->val) && checkChild(now->right,now->val,right);
    }
};