#include "create_tree.h"
#include "pretty_tree.h"
#include "../debugger.h"


int main() {
    //bug
    string line2("3,9,20,null,null,15,7");
    TreeNode* root = CreateTreeNode(line2);

    //right
    // string line("[3,9,20,null,null,15,7]");
    // TreeNode* root2 = stringToTreeNode(line);

    prettyPrintTree(root);
}

