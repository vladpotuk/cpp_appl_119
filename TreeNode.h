#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <vector>
#include <string>

class TreeNode {
public:
    TreeNode(int licensePlate);
    ~TreeNode();

    int getLicensePlate() const;
    const TreeNode* getLeft() const;
    const TreeNode* getRight() const;
    void addViolation(const std::string& violation);
    void printRecord() const;

private:
    int licensePlate;
    std::vector<std::string> violations;
    TreeNode* left;
    TreeNode* right;

    friend class Database; 
};

#endif 
