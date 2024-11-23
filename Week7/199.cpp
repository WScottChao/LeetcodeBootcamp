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
    void order(TreeNode* cur, vector<int>& result, int depth){
        if(cur == nullptr) return;
        if(result.size() == depth) 
            result.push_back(cur->val);
        order(cur->right, result, depth + 1);
        order(cur->left, result, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};