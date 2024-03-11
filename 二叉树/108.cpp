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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return findRoot(nums,0,nums.size()-1);
    }

//	递归的方法
    TreeNode* findRoot(vector<int>& nums,int left,int right)
    {
        int mid=(left+right)>>1;
        if (left > right) return nullptr;
        TreeNode* now=new TreeNode(nums[mid]);
        now->left=findRoot(nums,left,mid-1);
        now->right=findRoot(nums,mid+1,right);
        return now;
    }
};