#include "lib.h"

int main(int argc, char *argv[]) {
    TreeNode* root = createNode(1);

    addNode(root, 3);
    addNode(root, 6);
    addNode(root, 4);
    addNode(root, 7);
    addNode(root, 1);
    addNode(root, 2);
    addNode(root, 9);

    printDFS(root);

    free(root);
}
