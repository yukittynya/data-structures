#include "lib.h"

int main(int argc, char *argv[]) {
    LinkedList* root = create_list();

    prepend(root, 2);
    prepend(root, 3);
    append(root, 4);
    append(root, 5);

    delete(root, 2);

    print_list(root);
}
