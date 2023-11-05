#include "Resource.h"
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

/*
The example of bad function for for_each:
    auto ref = [](const Node& a) {const_cast<Node&>(a).children[0].reset(); };
*/
int main() {
    {
        auto doc = Resource::create();
        doc->load("test.txt");
        auto doc1 = doc->clone();
        doc->print();
        Node::Iterator it = doc->begin();
        while (it != doc->end()) {
            std::cout << it->getTag() << std::endl;
            it++;
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;

};