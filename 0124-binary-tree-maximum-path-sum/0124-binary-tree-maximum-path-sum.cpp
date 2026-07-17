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
    int solve(TreeNode* root, int& maxsum){
        if(root==NULL) return 0;

        int left= solve(root->left, maxsum);
        int right=solve(root->right, maxsum);

        int case1= root->val + left + right;
        int case2= root->val + max(left, right);
        int case3= root->val;

        maxsum= max({maxsum, case1, case2, case3});

        return max(case2, case3);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
};