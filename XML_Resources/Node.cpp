#include "Node.h"



int Node::numberInChildren(Node* point) {
    for (int i = 0; i < children.size(); i++)
        if (point == children[i].get()) return i;
    throw std::exception("It's not an child of this parent\n");
};

std::string Node::stringify(int depth) {
    const std::string indent = std::string(depth * 2, ' ');
    std::string result = "";

    result += indent + "<" + tag + ">" + "value=" + value;
    if (children.size()) {
        result += "\n";
    }
    for (const auto& child : children) {
        result += child->stringify(depth + 1);
    }
    if (children.size()) {
        result += indent;
    }
    result += "</" + tag + ">" + "\n";

    return result;
};

std::unique_ptr<Node>Node::copy() noexcept {
    if (!this) return nullptr;
    auto root = std::make_unique<Node>(Node(tag, value, parent));
    for (auto& child : children) {
        root->append(child->copy());
    }
    return root;
};

void Node::for_each(std::function<void(const Node&)> functor) {

    if (!this) throw std::exception("Your function has violated the integrity of the tree. Don't write like that anymore)");
    functor(*this);
    for (const auto& child : children) {
        child->for_each(functor);
    }
}

void Node::Iterator::next() {
    Node* cur = tmp->next();
    if (cur)
    {
        father = cur->parent;
        tmp = cur;
        return;
    }
    else {
        while (father->parent != nullptr) {
            int i = father->parent->numberInChildren(father);
            if (i < father->parent->children.size() - 1) {
                tmp = father->parent->children[i + 1].get();
                father = tmp->parent;
                return;
            }
            father = father->parent;
        }
        father = nullptr;
        tmp = nullptr;
        return;
    }
}

Node* Node::next()
{
    if (!children.empty()) return children[0].get();
    else if(parent != nullptr) {
        int i = parent->numberInChildren(this);
        if (i < parent->children.size() - 1)
            return parent->children[i + 1].get();
    }
    return nullptr;
}

void Node::Iterator::deleteNode() {
    
    for (int i = 0; i < father->children.size(); i++)
        if (father->children[i].get() == tmp)
        {
            father->children[i].reset();
            father->children.erase(father->children.begin() + i);
            break;
        }
}

void Node::erase(Node::Iterator& it) noexcept {
    auto& parent = *it->parent;
    auto& tmp = *it;
    
    for (int i = 0; i < it->children.size(); i++) {
        parent.append(std::move(tmp.children[i]));
    }
    it.deleteNode();
}
