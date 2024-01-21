#ifndef DATABASE_H
#define DATABASE_H

#include "TreeNode.h"

class Database {
public:
    Database();
    ~Database();

    void addRecord(int licensePlate, const std::string& violation);
    void printDatabase() const;
    void printRecord(int licensePlate) const;
    void printRecordsInRange(int startLicensePlate, int endLicensePlate) const;

private:
    TreeNode* root;

    void addRecordToTree(TreeNode* node, int licensePlate, const std::string& violation);
    void printInOrder(const TreeNode* node) const;
    void printInRange(const TreeNode* node, int startLicensePlate, int endLicensePlate) const;
    const TreeNode* findRecord(const TreeNode* node, int licensePlate) const;
};

#endif 
