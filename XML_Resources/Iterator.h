#include "Node.h"
#pragma once
/*
class Iterator : std::iterator<std::input_iterator_tag, Node>
{
	friend class Tree;
private:
    Iterator(Node* p) : pointer(p){};
public:
    Iterator(const Iterator& it) : Iterator(it.pointer){};
    bool operator!=(Iterator const& other) const { return pointer != other.pointer; };
    bool operator==(Iterator const& other) const { return pointer == other.pointer; }; //need for BOOST_FOREACH
    typename Iterator::reference operator*() const { return *pointer; };
    Iterator& operator++();
private:
    Node* pointer;
};*/

