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
#include <iostream>
using namespace std;

class Node {
// Update private section:
private:
    string data;
    int treeValue;
    Node* next;
    TreeNode* root;

    // Tree operations
    void insertToTree(char c);
    int calculateSubtreeValue(TreeNode* node, bool isLeft);
    void deleteTree(TreeNode* node);

    // Display helper functions
    int getHeight(TreeNode* node) const;
    void printSpaces(int count) const;
    void displayLevel(TreeNode* node, int level, int spacing) const;

    void mirrorSubtree(TreeNode* node);



public:
    Node(const string& data);
    ~Node();

    string getData() const;
    int getTreeValue() const;
    Node* getNext() const;
    void setNext(Node* next);
    void calculateTreeValue();

     void displayTree() const;
     void mirrorTree();
};

#endif