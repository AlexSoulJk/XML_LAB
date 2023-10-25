#include "Node.h"
std::string Node::stringify(const int depth) {
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

void Node::for_each(std::function<void(const Node&)> functor) {
    functor(*this);
    for (const auto& child : children) {
        child->for_each(functor);
    }
}