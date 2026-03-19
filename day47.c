#include <stdio.h>
#include <stdlib.h>

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}
