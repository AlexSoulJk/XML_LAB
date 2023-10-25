#include "Tree.h"
#pragma once
class Resource
{
	std::unique_ptr<Tree> XML_document;
	Resource(std::string const& fileName);
public:
	static Resource getResource(std::string const& fileName) {
		Resource tmp(fileName);
		return tmp;
	};
};

