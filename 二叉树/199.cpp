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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
//        用deque简单取最后一个元素
        deque<TreeNode*> q;
        q.push_back(root);
        while (q.size())
        {
            ans.push_back(q.back()->val);
            int cnt=q.size();
            for (int i=0; i<cnt; i++)
            {
                TreeNode* tem=q.front();
                q.pop_front();
                if (tem->left) q.push_back(tem->left);
                if (tem->right) q.push_back(tem->right);
            }
        }
        return ans;

    }
};