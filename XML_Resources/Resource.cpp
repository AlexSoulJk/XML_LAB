#include "Resource.h"

Resource::Resource() noexcept{
	XML_document = std::make_unique<Tree>();
};
void Resource::load(std::string const& path) {
	XML_document->load(path);
};
void Resource::print(void) {
	XML_document->print();
}

void Resource::for_each(std::function<void(const Node&)> fun) {
	try {
		XML_document->for_each(fun);
	}
	catch (std::exception& msg) {
		std::cout << msg.what();
	}
	
}