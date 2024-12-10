/**
 * @file        Node.hpp
 * @description declares the Node class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include "TreeNode.hpp"
using namespace std;

class Node {
private:
    string data;
    int treeValue;
    Node* next;
    TreeNode* root; //root of the BST

    void insertToTree(char c);
    int calculateSubtreeValue(TreeNode* node, bool isLeft);
    void deleteTree(TreeNode* node);

public:
    Node(const string& data);
    ~Node();

    string getData() const;
    int getTreeValue() const;
    Node* getNext() const;
    void setNext(Node* next);
    void calculateTreeValue();
};

#endif