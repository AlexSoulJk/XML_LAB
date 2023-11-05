#include "Resource.h"

Resource::Resource() noexcept{
	XML_document = std::make_unique<Tree>();
};
void Resource::load(std::string const& path) {
	try {
		XML_document->load(path);
	}
	catch (std::exception msg) {
		std::cout << msg.what();

	}
	
};
Resource::Resource(Resource const& res) noexcept {
	XML_document = std::make_unique<Tree>(*res.XML_document);
};
void Resource::print(void) {
	XML_document->print();
}

void Resource::for_each(std::function<void(const Node&)> fun) {
	auto copy = std::make_unique<Tree>(*XML_document);
	try {
		XML_document->for_each(fun);
	}
	catch (std::exception& msg) {
		std::cout << msg.what();
		XML_document = std::make_unique<Tree>(*copy);
	}
	
}

void Resource::save(const std::string& path) {
	try {
		XML_document->save(path);
	}
	catch (std::exception& msg) {
		std::cout << msg.what();
	}	
}

void Resource::parse(const std::string& xmlfile) {
	try {
		XML_document->parse(xmlfile);
	}
	catch (std::exception& msg) {
		std::cout << msg.what();
	}
};

Node::Iterator Resource::find_by_tag(std::string const& tag) noexcept {
	return XML_document->find_by_tag(tag);
}

Node::Iterator Resource::find_by_value(std::string const& value) noexcept {
	return XML_document->find_by_value(value);
};

bool Resource::add(std::string const& tag, std::string const& value, Node::Iterator const& it) {
	return XML_document->add(tag, value, it);
};

bool Resource::erase(Node::Iterator const& it) {
	return XML_document->erase(it);
}