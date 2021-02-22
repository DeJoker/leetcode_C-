/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res("[");
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) {
                res += "null,";
                continue;
            }
            res += to_string(node->val)+",";
            // res += (node->left ? to_string(node->left->val) : "null") +",";
            // res += (node->right ? to_string(node->right->val) : "null") +",";
            q.push(node->left);
            q.push(node->right);
        }
        res.back() = ']';
        return res;
    }

    inline vector<std::string> tokenize_str(const std::string & str, const std::string & delims)
    {
        // Skip delims at beginning, find start of first token
        string::size_type lastPos = str.find_first_not_of(delims, 0);
        // Find next delimiter @ end of token
        string::size_type pos = str.find_first_of(delims, lastPos);

        // output vector
        vector<string> tokens;

        while (string::npos != pos || string::npos != lastPos)
        {
            // Found a token, add it to the vector.
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            // Skip delims.  Note the "not_of". this is beginning of token
            lastPos = str.find_first_not_of(delims, pos);
            // Find next delimiter at end of token.
            pos = str.find_first_of(delims, lastPos);
        }

        return tokens;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="null") return nullptr;
        data = data.substr(1);
        data.pop_back();

        vector<string> tree = tokenize_str(data, ",");
        TreeNode* root = new TreeNode(atoi(tree[0].c_str()));

        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty() && i<tree.size()-2) {
            TreeNode* node = q.front(); q.pop();

            string ln = tree[i+1], rn = tree[i+2];
            i +=2;

            if (ln == "null") 
                node->left = nullptr;
            else {
                TreeNode* lN = new TreeNode(atoi(ln.c_str()));
                node->left = lN;
                q.push(lN);
            }

            if (rn == "null") 
                node->right = nullptr;
            else {
                TreeNode* rN = new TreeNode(atoi(rn.c_str()));
                node->right = rN;
                q.push(rN);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


int main() {
    Codec ser, deser;
    TreeNode* root = deser.deserialize("[1,2,3,null,null,4,5]");
    prettyPrintTree(root);
    cout << ser.serialize(root) << endl;
}
