#include "../common/debugger.h"
#include "../util/pretty_tree.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        deque<TreeNode*> st;
        TreeNode* p=root;
        int ret(0);
        while(p || !st.empty()) {
            if(p) {
                st.push_back(p);
                DebugDeque(st);
                int path(0);
                for(auto it=st.rbegin(); it!=st.rend(); ++it) {
                    path += (*it)->val;
                    if(path == sum)
                        ++ret;
                }
                p = p->left;
            } else {
                p = st.back(); st.pop_back();
                
                p = p->right;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    sol.pathSum(stringToTreeNode("[10,5,-3,3,2,null,11,3,-2,null,1]"), 8);
}
