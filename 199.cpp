#include "common/debugger.h"
#include "tree_util/pretty_tree.h"


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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> path;
        map<int, TreeNode*> rightmostValueAtDepth;
        if(!root) return path;

        typedef pair<TreeNode*, int> ViewType;
        queue<ViewType> traverse;
        traverse.push({root,1});

        int maxdepth(1);
        while(!traverse.empty()) {
            ViewType cur = traverse.front(); traverse.pop();

            TreeNode* node = cur.first;
            if (node != nullptr) {
                int depth = cur.second;
                maxdepth = max(maxdepth, depth);
                rightmostValueAtDepth[depth] = node;

                traverse.push({node->left, depth+1});
                traverse.push({node->right, depth+1});
            }
        }

        for(int depth=1; depth<=maxdepth; ++depth) {
            path.push_back(rightmostValueAtDepth[depth]->val);
        }

        return path;
    }
};


int main() {
    TreeNode* root = stringToTreeNode("[1,2,3,null,5,null]");

    Solution sol;
    auto vec = sol.rightSideView(root);
    DebugVecor(vec);
}
