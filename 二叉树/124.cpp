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
    int ans;
    int dfs(TreeNode* node)
    {
        if(!node) return 0;
        int l=dfs(node->left),r=dfs(node->right);
//        这里是当前作为路径最上方的根节点，只考虑左右两边的路径
        int down=node->val+max(0,l)+max(0,r);
//        这里还要继续向上走，所以只取左边和右边最大的那一条路径，如果左右都是小于0的，也可以只取当前结点
        int up=node->val+max(0,max(l,r));
        ans=max(ans,max(up,down));
        return up;
    }
public:
    int maxPathSum(TreeNode* root) {
        this->ans=INT_MIN;
        dfs(root);
        return this->ans;
    }
};