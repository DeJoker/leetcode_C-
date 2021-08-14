

#include "../common/debugger.h"

int maxCount = 0;

int MaxTreeXXX(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left_max = MaxTree(root->left);
    int right_max = MaxTree(root->right);

    if (!root->left && !root->right) {

    } else if (!root->left || !root->right) {

    } else if (root->left->val != root->right->val) {

    } else {
        maxCount++;

    }

    maxCount = max(left_max, right_max);


}



bool MaxTree(TreeNode* root) {
    if (!root->left && !root->right) {
        return false;
    } else if (!root->left || !root->right) {
        return false;
    } else if (root->left->val != root->right->val) {
        return false;
    } else {
        if MaxTree(root->left, root->right)
    }
}

