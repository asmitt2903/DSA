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
        int findSum(TreeNode* root,int& c1)
    {
        if(root == NULL) return 0;
        c1++;
        return root->val + findSum(root->left,c1) + findSum(root->right,c1);
    }
    void traverse(TreeNode* root,int& count)
    {
        if(root == NULL) return;
        int c1 = 0;
        int c2 = 0;
        int left = findSum(root->left,c1);
        int right = findSum(root->right,c2);
        if((root->val + left + right)/(c1+c2+1) == root->val) count++;
        traverse(root->left,count);
        traverse(root->right,count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};