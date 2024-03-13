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
//	这里和pta中建树的题差不多，分治的思想
    unordered_map<int,int> hash;
    vector<int> pre;
    TreeNode* Build(int root,int l,int r)
    {
        if (l > r) return nullptr;
        TreeNode* treeNode=new TreeNode(pre[root]);
        int pos=hash[pre[root]];
        treeNode->left=Build(root+1,l,pos-1);
        treeNode->right=Build(root+1+(pos-1-l+1),pos+1,r);
        return treeNode;
    }

public:
    

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->pre=preorder;
        for (int i=0; i<inorder.size(); i++) hash[inorder[i]]=i;
        return Build(0,0,preorder.size()-1);
    }
};