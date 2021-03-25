#include "../common/debugger.h"
#include "../util/pretty_tree.h"


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max1(INT_MIN), max2(INT_MIN);
        stack<tuple<TreeNode*, int, bool>> st;
        st.push({root, 0, false});
        while(!st.empty()) {
            auto [node, path, visit] = st.top();
            st.pop();
            if (!node) continue;
            if (!visit) {
                // 进入下一层要用path，但是第一次的路径要用root->val
                st.push({node->right, path+node->val, false});
                st.push({node->left, path+node->val, false});
                // if (node == root)
                //     st.push({node, path, true});
                // else
                    st.push({node, path+node->val, true});
            } else {
                if (path > max1) {
                    max2 = max1;
                    max1 = path;
                } else if (path > max2) {
                    max2 = path;
                }
            }
        }

        return max1 + max2;
    }
};


int main() {
    auto root = stringToTreeNode("[1,2,3]");
    cout << Solution().maxPathSum(root) << std::endl;
    return 0;
}


