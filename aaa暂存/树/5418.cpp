#include "../common/debugger.h"
#include "../util/pretty_tree.h"

class Solution {
public:
    int check(int *cnt) {
        int odd = 0;
        for(int i = 0; i <= 9; i++) {
            if(cnt[i]&1) {
                odd++;
            }
        }
        if(odd <= 1) {
            return 1;
        }
        return 0;
    }
    int dfs(TreeNode *root, int *cnt) {
        if(root == nullptr) {
            return 0;
        }
        cnt[root->val] ++;
        if(root->left == nullptr && root->right == nullptr) {
            int anw = check(cnt);
            cnt[root->val]--;
            return anw;
        }
        int anw = 0;
        anw += dfs(root->left, cnt);
        anw += dfs(root->right, cnt);
        cnt[root->val] --;
        return anw;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt[10] = {0};
        return dfs(root, cnt);
    }
};

int main() {
    Solution sol;
    auto ret = sol.pseudoPalindromicPaths(stringToTreeNode("[2,3,1,3,1,null,1]"));
    cout << ret << endl;
}