#include "TreeNode.h"

TreeNode::TreeNode(int licensePlate) : licensePlate(licensePlate), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

int TreeNode::getLicensePlate() const {
    return licensePlate;
}

const TreeNode* TreeNode::getLeft() const {
    return left;
}

const TreeNode* TreeNode::getRight() const {
    return right;
}

void TreeNode::addViolation(const std::string& violation) {
    violations.push_back(violation);
}

void TreeNode::printRecord() const {
    std::cout << "Номер машини: " << licensePlate << "\n";
    std::cout << "Правопорушення:\n";
    for (const auto& violation : violations) {
        std::cout << " - " << violation << "\n";
    }
    std::cout << "\n";
}
