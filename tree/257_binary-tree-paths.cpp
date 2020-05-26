#include "../common/debugger.h"
#include "../util/pretty_tree.h"




//递归推荐解法
class Solution {
public:
    // path不能传引用
    void ConstructPaths(TreeNode* root, string path, vector<string>& paths) {
        if (!root) 
            return;

        path += std::to_string(root->val);
        if (!root->left && !root->right)  // 当前节点是叶子节点
            paths.push_back(path);  // 把路径加入到答案中
        else {
            path += "->";  // 当前节点不是叶子节点，继续递归遍历
            ConstructPaths(root->left, path, paths);
            ConstructPaths(root->right, path, paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        ConstructPaths(root, "", paths);
        return paths;
    }
};


class Solution2 {
public:
    int ret;
    // int pseudoPalindromicPaths (TreeNode* root) {
    //     vector<int> path;
    //     binaryTreePaths(root, path);
    //     // DebugPlanarVector(vec);

    //     for(auto& pathE : vec) {
    //         map<int, int> cnt;
    //         for(auto& cc : pathE) {
    //             if (cnt.find(cc) != cnt.end()) {
    //                 --cnt[cc];
    //             } else {
    //                 ++cnt[cc];
    //             }
    //         }
    //         int notequeal(0);
    //         for(auto& ee : cnt) {
    //             if (ee.second)
    //                 ++notequeal;
    //         }
    //         if (notequeal < 2)
    //             ++ret;
    //     }
    //     return ret;
    // }
    
    vector<vector<int>> vec;
    
    vector<vector<int>> binaryTreePaths(TreeNode* root, vector<int>& path) {
        if(!root)
        {
            return vec;
        }
        
        if(!root->left && !root->right)
        {
            path.push_back(root->val);
            vec.push_back(path);
            return vec;
        }
        
        path.push_back(root->val);
        vector<int> path2 = path;
        
        binaryTreePaths(root->left, path);
        path = path2;
        
        binaryTreePaths(root->right, path);
        path = path2;
        
        return vec;
    }
};


int main() {
    Solution sol;
    stack<int> aa;
    sol.binaryTreePaths(stringToTreeNode("[2,3,1,3,1,null,1]"));
}