#include "Tree.h"

int main() {
    Tree* doc = new Tree();
    try {
        doc->load("test.txt");
    }
    catch (std::exception& r) {
        std::cout << "Start" << std::endl;
        std::cout << r.what() << std::endl;
        return 0;
    }

    doc->print();

    return 0;
};