#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <functional>
#pragma once


class Node {
private:
    Node* next();
public:

    class Iterator : std::iterator<std::input_iterator_tag, Node>
    {
    private:
        void next();
    public:
        Iterator(pointer p, pointer father) : tmp(p), father(father) {};
        Iterator(const Iterator& it) : Iterator(it.tmp, it.father) {};
        bool operator!=(Iterator const& other) const { return tmp != other.tmp || father != other.father; };
        bool operator==(Iterator const& other) const { return tmp == other.tmp && father == other.father; }; //need for BOOST_FOREACH
        pointer operator ->() { return tmp; };
        Iterator operator++ () { next(); return *this; };
        Iterator& operator++(int i) { Iterator tmp = *this; ++(*this); return tmp; };
        reference operator*() const { return *tmp; };

    private:
        pointer tmp;
        pointer father;
    };


    Node(const std::string& tag, const std::string& value, Node* parent) noexcept : tag(tag), value(value), parent(parent) {};

    std::unique_ptr<Node>copy() noexcept;

    void append(std::unique_ptr<Node> child) {
        children.emplace_back(std::move(child));
    }

    std::string stringify(int depth = 0);

    std::string getTag(void) { return tag; };
    std::string getValue(void) { return value; };

    void for_each(std::function<void(const Node&)>);
    int numberInChildren(Node*);

    Iterator begin() { return Iterator(this, nullptr); };
    Iterator end() { return Iterator(nullptr, nullptr); }
    void erase(Iterator it) noexcept;
private:
    std::string tag;
    std::string value;
    Node* parent;
    //~Node() = default;
public: 
    std::vector<std::unique_ptr<Node>> children;
};