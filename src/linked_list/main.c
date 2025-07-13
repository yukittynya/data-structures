#include "lib.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    LinkedList* root = create_list();

    prepend(root, 2);
    prepend(root, 3);
    append(root, 4);
    append(root, 5);

    delete(root, 2);

    print_list(root);

    int target = 3;

    if (exists(root, target)) {
        printf("%d exists\n", target);
    } else {
        printf("%d does not exist\n", target);
    }
}
