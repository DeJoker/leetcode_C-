/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include "../common/debugger.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// @lc code=start

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int qsize  = q.size();
            for(int i=0; i<qsize; i++) {
                auto node = q.front(); q.pop();
                if (!node) continue;
                if (i<qsize-1) {
                    node->next = q.front();
                } else {
                    node->next = nullptr;
                }

                q.push(node->left);
                q.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end


int main() {
    // LOG_DEBUG << Solution().connect(root);
    return 0;
}
