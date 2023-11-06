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
        doc->save("output_test.txt");
        auto it = doc->find_by_tag("TAG7");
        doc->erase(it);
        doc->save("output_test_withoutTAG7.txt");
        auto it_begin = doc->begin();
        doc->add("TAG99","99", it_begin);
        doc->save("output_test_withTAG99.txt");
    }
    _CrtDumpMemoryLeaks();
    return 0;

};