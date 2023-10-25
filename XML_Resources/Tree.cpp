#include "Tree.h"

void Tree::parse(const std::string& xml) {
    int pos = 0;
    root_node = parseNode(xml, pos);
};

std::unique_ptr<Node> Tree::parseNode(const std::string& xml, int& pos) {
    std::string tag, value;
    getNextTag(xml, pos, tag);
    getNextValue(xml, pos, value);
    std::unique_ptr<Node> node(new Node(tag, value));

    std::string nextTag;
    getNextTag(xml, pos, nextTag);
    while (nextTag != ("/" + tag) && pos < xml.size()) {
        pos -= nextTag.size() + 2;
        node->append(parseNode(xml, pos));
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
    const std::string xml = read_file(path);
    parse(xml);
};
void Tree::save(const std::string& path) {
    std::string xml = stringify();
    write_file(path, xml);
};
void Tree::print() {
    std::string xml = stringify();
    std::cout << xml << std::endl;
};
void Tree::for_each(std::function<void(const Node&)> Functor) {
    root_node->for_each(Functor);
};


std::string Tree::read_file(const std::string& path) {
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
void Tree::write_file(const std::string& path, const std::string& content) {
    std::ofstream file(path);

    if (!file) {
        throw std::runtime_error("File not found");
    }

    file << content;
};
std::string Tree::stringify() {
    return root_node->stringify();
};