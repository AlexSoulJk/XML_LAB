#include "Tree.h"

void Tree::parse(const std::string& xml) {
    int pos = 0;
    root_node = parseNode(xml, pos, nullptr);
};

Tree::Tree(Tree const& tree) {
    root_node = tree.root_node->copy();
}

std::unique_ptr<Node> Tree::parseNode(const std::string& xml, int& pos, Node* parent) {
    std::string tag, value;
    getNextTag(xml, pos, tag);
    getNextValue(xml, pos, value);
    std::unique_ptr<Node> node(new Node(tag, value, parent));

    std::string nextTag;
    getNextTag(xml, pos, nextTag);
    while (nextTag != ("/" + tag) && pos < xml.size()) {
        pos -= nextTag.size() + 2;
        node->append(parseNode(xml, pos, node.get()));
        getNextTag(xml, pos, nextTag);
    }
    return node;
}

void Tree::getNextTag(const std::string& expression, int& index, std::string& tag) {
    std::string res = "";
    index++;
    do {
        res += expression[index++];
    } while ((expression[index] != '>'));
    index++;
    tag = res;
}

bool Tree::CheackSimForVal(std::string const& expression, int& index) {
    std::string value_expres_const = "value=";
    for (int j = 0; j < 6; j++) {
        if (expression[j + index] != value_expres_const[j]) return false;
    }
    index += 6;
    return true;

}

void Tree::getNextValue(const std::string& expression, int& index, std::string& value) {
    std::string res = "";
    if (CheackSimForVal(expression, index)) {
        do {
            res += expression[index++];
        } while ((expression[index] != '<'));
    }
    else throw std::exception("Ban value\n");
    value = res;
}

void Tree::load(const std::string& path) {
    const std::string xml = readFile(path);
    parse(xml);
};

void Tree::save(const std::string& path) {
    std::string xml = stringify();
    writeFile(path, xml);
};

void Tree::print() {
    std::string xml = stringify();
    std::cout << xml << std::endl;
};

void Tree::for_each(std::function<void(const Node&)> Functor) {
    root_node->for_each(Functor);
};

std::string Tree::readFile(const std::string& path) {
    std::ifstream file(path);
    std::string expression = "", cur = "";

    if (file.is_open()) {
        while (file >> cur) {
            expression += cur;
        }
        std::cout << "succes loading" << std::endl;
        return expression;
        //parse(expression);
    }
    file.close();
    throw std::exception("File not found");

};

void Tree::writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);

    if (!file) {
        throw std::runtime_error("File not found");
    }

    file << content;
};

std::string Tree::stringify() {
    return root_node->stringify();
};

Node::Iterator Tree::find_by_tag(std::string const& tag){
    auto it = begin();
    auto end_ = end();
    while (it != end_) {
        if (it->getTag() == tag) {
            return it;
        }
        it++;
    }
    throw std::exception(("This tree has not got " + tag).c_str());
};

Node::Iterator Tree::find_by_value(std::string const& value) {
    auto it = begin();
    auto end_ = end();
    while (it != end_) {
        if (it->getValue() == value) {
            return it;
        }
        it++;
    }
    throw std::exception(("This tree has not got " + value).c_str());
};

bool Tree::isIteratorValid(Node::Iterator const& it) noexcept{
    auto begin_ = begin();
    auto end_ = end();
    if (it == end_) return false;
    while (begin_ != end_) {
        if (begin_ == it) return true;
        begin_++;
    }
    return false;
};


bool Tree::add(std::string const& tag, std::string const& value, Node::Iterator const& it) noexcept{
    if (!isIteratorValid(it)) return false;
    (*it).append(std::unique_ptr<Node>(new Node(tag, value, &(*it))));
    return true;
};

bool Tree::erase(Node::Iterator& it) noexcept {
    if (!isIteratorValid(it) || it == begin()) return false;
    root_node->erase(it);
    return true;

}