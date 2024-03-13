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
private:
    int ans=0;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int l=0,r=0;
        if (root->left) l=dfs(root->left);
        if (root->right) r=dfs(root->right);
        ans=max(ans,l+r+1);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
//        这里计算路径长度，不是节点数量
        return ans-1;
    }
};