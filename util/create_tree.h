#ifndef __CREATE_TREE_H_
#define __CREATE_TREE_H_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#include <cstdio>

#include "pretty_tree.h"

// "../common/debugger.h"
template<typename Ty>
void DebugVector(const vector<Ty>& mm);

/*
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   
};
*/

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

inline TreeNode* createNode(string integer)
{
    TreeNode* node = new TreeNode(std::atoi(integer.c_str()));
    // cout << node->val << endl;
    return node;
}

void CreatBiTree(TreeNode* T)
{ // 先序递归创建二叉树
// 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
    char ch;
    for (int j = 0; j < 13; ++j)
    {
        if ((ch = getchar()) == '#') // getchar() 为逐个读入标准库函数
            T = NULL;
        else
        {
            T = new TreeNode;
            T->val = ch;
            CreatBiTree(T->left);
            CreatBiTree(T->right);
        }
    }
}

TreeNode* CreateTreeNode(string aa)
{
    auto vec = tokenize_str(aa, ",");
    if (vec.empty()) return NULL;

    DebugVector(vec);

    queue<TreeNode*> traverse;
    TreeNode* root = createNode(vec[0]);
    traverse.push(root);

    // 漏写了一个++i，是在输出过程中才发现的问题
    for (int i=1; i<vec.size(); ++i)
    {
        TreeNode* node = traverse.front(); traverse.pop();
        if (vec[i] == "null") {
            node->left = nullptr;
        } else {
            TreeNode* newNode = createNode(vec[i]);
            node->left = newNode;
            traverse.push(newNode);
        }

        ++i;
        if(i == vec.size()) {
            break;
        }

        if (vec[i] == "null") {
            node->right = nullptr;
        } else {
            TreeNode* newNode = createNode(vec[i]);
            node->right = newNode;
            traverse.push(newNode);
        }
    }
    // 1. 没写返回值
    return root;
}


#endif
