#include "../common/debugger.h"
#include "../util/pretty_tree.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<pair<bool, TreeNode*>> st;
        st.push({false, root});
        while(!st.empty()) {
            auto [visit, node] = st.top(); st.pop();
            if (!node) continue;
            if (!visit) {
                st.push({false, node->right});
                st.push({false, node->left});
                st.push({true, node});
            } else {
                ret.push_back(node->val);
            }
        }
        return ret;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while(!st.empty()) {
            auto [node, visit] = st.top();
            st.pop();
            if(!node) continue;
            if (!visit) {
                st.push({root->right, false});
                st.push({root->left, false});
                st.push({root, true});
            } else {
                path += to_string(root->val);
                if(!root->left && !root->right) {
                    ret.push_back(path);
                } else {
                    path += "->";
                }
            }
        }
        return ret;
    }

};

int main() {
    Solution sol;
    // auto ret = sol.preorderTraversal(stringToTreeNode("[1,2,3,null,5]"));
    auto ret = sol.binaryTreePaths(stringToTreeNode("[1,2,3,null,5]"));
    DebugVecor(ret);
}