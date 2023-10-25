#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#pragma once


class Node {
public:
    std::string tag;
    std::string value;
    std::vector<std::unique_ptr<Node>> children;

    Node(const std::string& tag, const std::string& value) : tag(tag), value(value) {}

    void append(std::unique_ptr<Node> child) {
        children.emplace_back(std::move(child));
    }
    std::string stringify(const int depth = 0) {
        const std::string indent = std::string(" ", depth * 2);
        std::string result = "";

        result += indent + "<" + tag + ">" + "value=" + value;
        if (children.size()) {
            result += "\n";
        }
        std::cout << tag << " " << "\"" << "value=" + value << "\"" << " " << depth << std::endl;
        for (const auto& child : children) {
            result += child->stringify(depth + 1);
        }
        if (children.size()) {
            result += indent;
        }
        result += "</" + tag + ">" + "\n";

        return result;
    };
};