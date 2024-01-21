#include "Database.h"

Database::Database() : root(nullptr) {}

Database::~Database() {
    delete root;
}

void Database::addRecord(int licensePlate, const std::string& violation) {
    if (!root) {
        root = new TreeNode(licensePlate);
        root->addViolation(violation);
    }
    else {
        addRecordToTree(root, licensePlate, violation);
    }
}

void Database::addRecordToTree(TreeNode* node, int licensePlate, const std::string& violation) {
    if (licensePlate < node->getLicensePlate()) {
        TreeNode* left = const_cast<TreeNode*>(node->getLeft());
        if (left) {
            addRecordToTree(left, licensePlate, violation);
        }
        else {
            const_cast<TreeNode*>(node)->left = new TreeNode(licensePlate);
            const_cast<TreeNode*>(node->getLeft())->addViolation(violation);
        }
    }
    else if (licensePlate > node->getLicensePlate()) {
        TreeNode* right = const_cast<TreeNode*>(node->getRight());
        if (right) {
            addRecordToTree(right, licensePlate, violation);
        }
        else {
            const_cast<TreeNode*>(node)->right = new TreeNode(licensePlate);
            const_cast<TreeNode*>(node->getRight())->addViolation(violation);
        }
    }
    else {
        node->addViolation(violation);
    }
}

void Database::printDatabase() const {
    printInOrder(root);
}

void Database::printRecord(int licensePlate) const {
    const TreeNode* node = findRecord(root, licensePlate);
    if (node) {
        node->printRecord();
    }
    else {
        std::cout << "Запис з номером машини " << licensePlate << " не знайдено.\n";
    }
}

void Database::printRecordsInRange(int startLicensePlate, int endLicensePlate) const {
    printInRange(root, startLicensePlate, endLicensePlate);
}

void Database::printInOrder(const TreeNode* node) const {
    if (node) {
        printInOrder(node->getLeft());
        node->printRecord();
        printInOrder(node->getRight());
    }
}

void Database::printInRange(const TreeNode* node, int startLicensePlate, int endLicensePlate) const {
    if (node) {
        if (node->getLicensePlate() >= startLicensePlate && node->getLicensePlate() <= endLicensePlate) {
            node->printRecord();
        }
        if (node->getLicensePlate() < endLicensePlate) {
            printInRange(node->getRight(), startLicensePlate, endLicensePlate);
        }
        if (node->getLicensePlate() > startLicensePlate) {
            printInRange(node->getLeft(), startLicensePlate, endLicensePlate);
        }
    }
}

const TreeNode* Database::findRecord(const TreeNode* node, int licensePlate) const {
    if (!node) {
        return nullptr;
    }

    if (licensePlate < node->getLicensePlate()) {
        return findRecord(node->getLeft(), licensePlate);
    }
    else if (licensePlate > node->getLicensePlate()) {
        return findRecord(node->getRight(), licensePlate);
    }
    else {
        return node;
    }
}
