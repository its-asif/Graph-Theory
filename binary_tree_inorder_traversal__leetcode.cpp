//  OJ          : Leetcode
//  Problem Name: Binary Tree Inorder Traversal
//  Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
    

class Solution {
public:
    void inorderBTree(TreeNode* x, vector<int> &sol){
        if( x == NULL) return;
        inorderBTree(x->left, sol);
        sol.push_back(x->val);
        inorderBTree(x->right, sol);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        inorderBTree(root, sol);
        return sol;
    }
};