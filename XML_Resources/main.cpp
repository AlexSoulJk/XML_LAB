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
        auto it = doc->find_by_tag("TAG150");
        //doc->erase(it);
        //doc->print();
        doc->add("TAG170","370",it);
        doc->print();
    }
    _CrtDumpMemoryLeaks();
    return 0;

};