#include "Resource.h"


/*
The example of bad function for for_each:
    auto ref = [](const Node& a) {const_cast<Node&>(a).children[0].reset(); };
*/
int main() {
    Resource doc = Resource::getResource("test.txt");   
    doc.print();
    return 0;
};