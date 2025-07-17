#include "lib.h"

#include <stdlib.h>
#include <stdio.h>

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));

    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

TreeNode* addNode(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (root -> value == value) {
        return root;
    }

    if (root -> value < value) {
        root -> right = addNode(root -> right, value);
    } else {
        root -> left = addNode(root -> left, value);
    }

    return root;
}

void printDFS(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printDFS(root -> left);
    printf("%d\n", root -> value);
    printDFS(root -> right);
}
