/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    map<TreeNode*, TreeNode*> mp;

    void dfs(TreeNode* node, TreeNode* par) {
        if (!node) return;
        mp[node] = par;
        dfs(node->left, node);
        dfs(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, nullptr);

        queue<TreeNode*> qu;
        set<TreeNode*> visit;
        visit.insert(target);
        qu.push(target);

        while(!qu.empty()) {
            --K;
            if (K < 0) { // 这里注意是后置--，保证k刚等于0还会进入一次
                vector<int> res;
                while(!qu.empty()) {
                    auto node = qu.front(); qu.pop();
                    res.push_back(node->val);
                }
                return res;
            } else {
                int len = qu.size();
                for(int i=0; i<len; i++) {
                    auto node = qu.front(); qu.pop();
                    if (node->left && visit.find(node->left) == visit.end()) {
                        qu.push(node->left);
                        visit.insert(node->left);
                    }
                    if (node->right && visit.find(node->right) == visit.end()) {
                        qu.push(node->right);
                        visit.insert(node->right);
                    }
                    auto par = mp[node];
                    if (par && visit.find(par) == visit.end()) {
                        qu.push(par);
                        visit.insert(par);
                    }

                }
            }
        }
        return {};
    }
};
// @lc code=end


int main() {
    auto root = stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    auto xx = Solution().distanceK(root, root->left, 2);
    DebugVector(xx);
}
