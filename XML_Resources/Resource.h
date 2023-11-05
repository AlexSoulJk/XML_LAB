#include "Tree.h"
#pragma once
class Resource
{
	std::unique_ptr<Tree> XML_document;
	Resource() noexcept;
	Resource(Resource const&) noexcept;
public:
	static std::unique_ptr<Resource> create() {
		return std::unique_ptr<Resource>(new Resource());
	};
	std::unique_ptr<Resource> clone() { return std::unique_ptr<Resource>(new Resource(*this)); };
	void print(void);
	void load(std::string const& path);
	void for_each(std::function<void(const Node&)>);
	void save(const std::string& path);
	void parse(const std::string&);

	Node::Iterator begin() { return XML_document->begin(); };
	Node::Iterator end() { return XML_document->end(); };
	Node::Iterator find_by_tag(std::string const& tag) noexcept;
	Node::Iterator find_by_value(std::string const& value) noexcept;

	bool add(std::string const& tag, std::string const& value, Node::Iterator const & it) noexcept;
	bool erase(Node::Iterator const& it) noexcept;
	~Resource() = default;
};

