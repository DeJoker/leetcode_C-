/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 */
#include "../common/debugger.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int N) {
        if (memo.find(N) == memo.end()) {
            vector<TreeNode*> dp;
            if (N==1) {
                dp.push_back(new TreeNode(0));
            } else if (N%2 == 1) {
                // 确定左右子树个数
                for(int x=1; x<N-1; ++x) {
                    int y=N-1-x;
                    // 左右子树异构
                    for(auto lans : allPossibleFBT(x)) {
                        for(auto rans : allPossibleFBT(y)) {
                            TreeNode* node = new TreeNode(0);
                            node->left = lans;
                            node->right = rans;
                            dp.push_back(node);
                        }
                    }
                }
            }
            memo[N] = dp;
        }
        return memo[N];
    }
};
// @lc code=end

int main() {
    Solution k;
    auto zz = k.allPossibleFBT(7);
    return 0;
}

