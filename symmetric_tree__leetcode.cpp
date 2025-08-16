//  OJ          : Leetcode
//  Problem Name: Symmetric Tree
//  Problem Link: https://leetcode.com/problems/symmetric-tree/
    

class Solution {
public:
    bool IsSame(TreeNode* l, TreeNode* r){
        if(l == NULL or r == NULL){
            return (l == r);
        }
        cout << l->val <<' '<< r->val<<endl;

        return (l->val == r->val)
            && IsSame(l->left, r-> right)
            && IsSame(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return IsSame(root->left, root->right);
    }
};