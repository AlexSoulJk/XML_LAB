#include "Resource.h"
Resource::Resource(std::string const& fileName) {
	Tree tmp;
	tmp.load(fileName);
	XML_document = std::make_unique<Tree>(tmp);
};