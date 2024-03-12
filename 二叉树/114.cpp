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
    void flatten(TreeNode* root) {
        TreeNode* now=root;
        if (root == nullptr) return;
        while (now != nullptr)
        {
            if (now->left != nullptr)
            {
                TreeNode* tem=now->left;
                TreeNode* nxtRight=tem;
                while (nxtRight->right != nullptr)
                {
                    nxtRight=nxtRight->right;
                }
                nxtRight->right=now->right;
                now->left=nullptr;
                now->right=tem;
            }
            now=now->right;
        }        
    }
};