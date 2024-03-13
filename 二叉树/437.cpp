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
    int cnt;
    long long targetSum;
//    自己写的dfs，不用long long有可能会溢出啥的
    void dfs(TreeNode* node,long long sum,int flag)
    {
        if ((long long)sum+node->val == targetSum) cnt++;
        if (node)
        {
            if (node->left)
            {
                if (!flag) dfs(node->left,0,0);
                dfs(node->left,sum+node->val,1);
            }
            if (node->right)
            {
                if (!flag) dfs(node->right,0,0);
                dfs(node->right,sum+node->val,1);
            }
        }
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        this->cnt=0;
        this->targetSum=targetSum;
        if (root) dfs(root,0,0);
        return this->cnt;
    }
};