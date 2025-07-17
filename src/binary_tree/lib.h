#ifndef LIB_H
#define LIB_H

#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value);
TreeNode* addNode(TreeNode* root, int value);
void printDFS(TreeNode* root);

#endif // !LIB_H
