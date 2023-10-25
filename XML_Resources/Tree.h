#include "Node.h"
#pragma once


class Tree {
public:
    Tree() noexcept : root_node(nullptr) {};
    void parse(const std::string& xml);
    void load(const std::string& path);
    void save(const std::string& path);
    void print();
    void for_each(std::function<void(const Node&)>);
private:
    std::unique_ptr<Node> root_node;

    std::string readFile(const std::string& path);
    void writeFile(const std::string& path, const std::string& content);
    std::string stringify();
    void getNextTag(const std::string& expression, int& index, std::string& tag);
    bool CheackSimForVal(std::string const& expression, int& index);
    void getNextValue(const std::string& expression, int& index, std::string& value);
    std::unique_ptr<Node> parseNode(const std::string& xml, int& pos);
};