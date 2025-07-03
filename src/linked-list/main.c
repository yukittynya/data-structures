#include "lib.h"

int main(int argc, char *argv[]) {
    LinkedList* root = create_list();

    prepend(root, 2);
    prepend(root, 3);
    append(root, 4);
    append(root, 5);

    quick_sort(root, 0, root -> count);

    print_list(root);
}
