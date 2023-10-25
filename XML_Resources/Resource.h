#include "Tree.h"
#pragma once
class Resource
{
	std::unique_ptr<Tree> XML_document;
	Resource() noexcept;

public:
	static Resource getResource(std::string const& fileName) {
		Resource tmp;
		try {
			tmp.load(fileName);
		}
		catch (std::exception& msg) {
			std::cout << msg.what() << std::endl;
		}
		return tmp;
	};
	void print(void);
	void load(std::string const& path);
	void for_each(std::function<void(const Node&)>);
	void save(const std::string& path);
	void parse(const std::string&);
};

