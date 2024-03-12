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
    int num,ans;

//	dfs查找中序遍历
    void dfs(TreeNode* now)
    {
        if (now == nullptr) return;
        dfs(now->left);
        if (num == 0) return;
        num--;
        if (!num) ans=now->val;
        dfs(now->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        num=k;
        dfs(root);
        return ans;
    }
};