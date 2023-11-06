#include "Resource.h"

Resource::Resource() noexcept{
	XML_document = std::make_unique<Tree>();
};
void Resource::load(std::string const& path) {
	try {
		XML_document->load(path);
	}
	catch (std::exception const& msg) {
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
	catch (std::exception const& msg) {
		std::cout << msg.what();
		XML_document = std::make_unique<Tree>(*copy);
	}
	
}

void Resource::save(const std::string& path) {
	try {
		XML_document->save(path);
	}
	catch (std::exception const& msg) {
		std::cout << msg.what();
	}	
}

Node::Iterator Resource::find_by_tag(std::string const& tag) {
	auto tmp = end();
	try {
		tmp = XML_document->find_by_tag(tag);
	}
	catch (std::exception const& msg) {
		std::cout << msg.what() << std::endl;
	}
	return tmp;
	
}

Node::Iterator Resource::find_by_value(std::string const& value) {
	auto tmp = end();
	try {
		tmp = XML_document->find_by_value(value);
	}
	catch (std::exception const& msg) {
		std::cout << msg.what() << std::endl;
	}
	return tmp;
};

bool Resource::add(std::string const& tag, std::string const& value, Node::Iterator& it) noexcept{
	bool res = true;
	res = XML_document->add(tag, value, it);
	if(!res) std::cerr << "Adding " << tag << " with value " << value << " is failed!" << std::endl;
	return res;
};

bool Resource::erase(Node::Iterator& it) noexcept{
	bool res = true;
	res = XML_document->erase(it);
	if (!res) std::cerr << "Erassing is failed!" << std::endl;
	return res;
}