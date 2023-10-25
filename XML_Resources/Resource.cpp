#include "Resource.h"
Resource::Resource(std::string const& fileName) {
	XML_document = std::make_unique<Tree>();
	XML_document->load(fileName);
};