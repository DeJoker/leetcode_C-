#include "../../common/debugger.h"
#include "../../tree_util/pretty_tree.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        stack<TreeNode*> path;
        // vector<TreeNode*> findl,findr;
        TreeNode* cur = root, *common;
        bool findOne(false);
        while(cur || !path.empty()) {
            if(cur) {
                path.push(cur);

                //很奇怪，本地debug的时候，cur有时不在栈中？？
                // if (cur == p) {
                //     findl = {path.begin(), path.end()};
                // }
                // if (cur == q) {
                //     findr = path;
                // }
                // if (findl.empty() && !findr.empty()) {
                //     break;
                // }

                if (!findOne && cur == p) {
                    findOne = true;
                    common = p;
                }
                if (!findOne && cur == q) {
                    findr = path;
                }

                cur = cur->left;
                // path.push(cur->left); // 之前居然写成了直接push？？？
            } else {
                cur = path.top();
                path.pop();
                cur = cur->right;
            }
        }

        for(auto l=findl.top(), r=findr.top(); !findl.empty(); findl.pop(), findr.pop()) {
            if (l == r)
                return l;
            l = findl.top();
            r = findr.top();
        }
        return nullptr;
    }
};

int main() {
    auto root = stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
    Solution sol;
    sol.lowestCommonAncestor(root, root->left, root->right);
    return 0;
}


// Line 157: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0b6 for type 'TreeNode *', which requires 8 byte alignment (stl_deque.h)
// 0xbebebebebebec0b6: note: pointer points here
// <memory cannot be printed>
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/bits/stl_deque.h:162:16
