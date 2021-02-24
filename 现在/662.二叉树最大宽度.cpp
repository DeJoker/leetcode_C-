/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */
#include "../common/debugger.h"

// @lc code=start
/**
 * Definition for pos binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution33 {
public:
    size_t ans=0;

    int dfs(TreeNode* node) {
        
    }

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        q.push({0,root});
        while(!q.empty()) {
            ans = max(ans, q.size());
            auto [level, node] = q.front(); q.pop();
            while(q.front().first == level) {
                auto n = q.front().second; q.pop();
                if (n) {
                    q.push({level+1, n->left});
                    q.push({level+1, n->right});
                }
            }
        }
        return ans;
    }
};


// 2 * 1610612735
// 超过了int最大值
// int sum;
//         int ans = 0;
//         while(!queue.isEmpty()) {
//             sum = queue.size();
//             // 队头和队尾的编号值求差用来更新宽度
//             ans = Math.max(ans, queue.getLast().val - queue.getFirst().val + 1);
//             // 一次处理一层，进入这个循环前队列中是一层的所有非空节点
//             while(sum > 0) {

class SolutionXXX {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = 1;

        deque<int> lists;
        lists.push_back(1);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = (int)q.size();
            while(sz--)
            {
                auto node = q.front(); q.pop();
                int pos = lists.front(); lists.pop_front();
                if(node->left) {
                    q.push(node->left);
                    lists.push_back(2*pos);
                }
                if(node->right) {
                    q.push(node->right);
                    lists.push_back(2*pos + 1);
                    
                }
                
            }
            if (lists.size() > 1) {
                res = max(res, lists.back() - lists.front() + 1);
            }
            
        }
        return res;
    }
};

// 因为求得是宽度，不需要记录层数，内置循环把一层所有遍历完即可

// 如何防止极端情况整数越界。有一个用例是线性的树，所以如果每层都乘以2很快就越界了
// 我们采用每次进入新的一层的时候记录queue 头部的index - 1 作为delta
// 这样每个坐标都减去delta重新调整为从1开始，而且保持相对位置关系不变，避免了越界。
// 这样用int类型就可以了，否则unsigned long long 都不够用，照样越界
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int res = 1;
        list<int> idxList = {1};     
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            // Adjust delta for each level to keep the relative diff between level nodes!
            // to avoid integer overflow problem which doesn't exist in java and python
            auto delta = idxList.front() - 1;
            for (int k = q.size(); k > 0; k--) {
                auto index = idxList.front(); idxList.pop_front();
                index -= delta;
                auto cur = q.front(); q.pop();
                if (cur->left) {
                    q.push(cur->left);
                    idxList.push_back(index * 2);
                }
                if (cur->right) {
                    q.push(cur->right);
                    idxList.push_back(index * 2 + 1);
                }
            }
            res = max(res, idxList.back() - idxList.front() + 1);
        }

        return res;
    }
};


// @lc code=end


int main() {
    TreeNode* root;

    root = stringToTreeNode("[1,2,3,4,5]");
    // LOG_DEBUG << Solution().widthOfBinaryTree(root);
    // root = stringToTreeNode("[1,3,2,5,3,null,9]");
    // LOG_DEBUG << Solution().widthOfBinaryTree(root);


    // root = stringToTreeNode("(1,3,2,5,null,null,9,6,null,null,7)");
    // prettyPrintTree(root);
    // LOG_DEBUG << Solution().widthOfBinaryTree(root);

    // root = stringToTreeNode("(1,3,2,5,null)");
    // LOG_DEBUG << Solution().widthOfBinaryTree(root);


    root = stringToTreeNode("[0,0,0,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null]");
    LOG_DEBUG << Solution().widthOfBinaryTree(root);
}
