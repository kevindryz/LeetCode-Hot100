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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
//        空指针需要特判
        if (!root) return ans;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size())
        {
            int num=q.size();
            for (int i=0; i<num; i++)
            {
                TreeNode* now=q.front();
                q.pop();
                v.push_back(now->val);
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;

    }
};