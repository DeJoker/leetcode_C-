/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
 */
#include "../common/debugger.h"

// @lc code=start
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
    int ans = 0;
    int dis;

    // 公共祖先节点为node，然后查找所有叶子节点的距离
    // 怎么保证只有叶子节点呢，注意有叶子节点才是baseCase返回了距离0的单数组
    vector<int> dfs(TreeNode* node) {
        if (!node) return {};
        if (!node->left && !node->right) {
            return {0};
        }

        auto vl = dfs(node->left);
        for(auto& l : vl) {
            ++l;
        }
        auto vr = dfs(node->right);
        for(auto& r : vr) {
            ++r;
        }
        for (auto l : vl) {
            for(auto r : vr) {
                if (l+r <= dis) {
                    ans++;
                }
            }
        }
        vl.insert(vl.end(), vr.begin(), vr.end());
        return vl;
    }

    int countPairs(TreeNode* root, int distance) {
        dis = distance;
        dfs(root);
        return ans;
    }
};
// @lc code=end

int main() {
    auto root = stringToTreeNode("[1,2,3,null,4]");
    LOG_DEBUG << Solution().countPairs(root, 3);

    root = stringToTreeNode("[1,2,3,4,5,6,7]");
    LOG_DEBUG << Solution().countPairs(root, 3);

    root = stringToTreeNode("[7,1,4,6,null,5,3,null,null,null,null,null,2]");
    LOG_DEBUG << Solution().countPairs(root, 3);

    root = stringToTreeNode("[100]");
    LOG_DEBUG << Solution().countPairs(root, 1);

}

