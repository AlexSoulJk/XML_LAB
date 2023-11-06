#include "Node.h"
#pragma once


class Tree {
private:
    std::unique_ptr<Node> root_node;
public:
    Tree() noexcept : root_node(nullptr) {};
    Tree(Tree const& tree);
    ~Tree() = default;

    void parse(const std::string& xml);
    void load(const std::string& path);
    void save(const std::string& path);
    void print();
    void for_each(std::function<void(const Node&)>);

    Node::Iterator begin() { return root_node->begin(); };
    Node::Iterator end() { return root_node->end(); };

    Node::Iterator find_by_tag(std::string const& tag);
    Node::Iterator find_by_value(std::string const& value);

    bool add(std::string const& tag, std::string const& value, Node::Iterator const& it) noexcept;
    bool erase(Node::Iterator& it)noexcept;
private:
    std::string readFile(const std::string& path);
    void writeFile(const std::string& path, const std::string& content);
    std::string stringify();
    void getNextTag(const std::string& expression, int& index, std::string& tag);
    bool CheackSimForVal(std::string const& expression, int& index);
    void getNextValue(const std::string& expression, int& index, std::string& value);
    std::unique_ptr<Node> parseNode(const std::string& xml, int& pos, Node* parent);
    bool isIteratorValid(Node::Iterator const& it) noexcept;
};