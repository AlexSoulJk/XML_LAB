#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <functional>
#pragma once


class Node {
    std::string tag;
    std::string value;
   
public:
    std::vector<std::unique_ptr<Node>> children;
    Node(const std::string& tag, const std::string& value) noexcept : tag(tag), value(value) {};

    void append(std::unique_ptr<Node> child) {
        children.emplace_back(std::move(child));
    }
    std::string stringify(const int depth = 0);

    void for_each(std::function<void(const Node&)>);
};