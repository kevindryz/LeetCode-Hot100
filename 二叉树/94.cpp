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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* now=root;
//        迭代的方法
        while (now != nullptr || s.size())
        {
            while (now != nullptr)
            {
                s.push(now);
                now=now->left;
            }
            now=s.top();
            s.pop();
            ans.push_back(now->val);
            now=now->right;
        }
        return ans;
    }
};