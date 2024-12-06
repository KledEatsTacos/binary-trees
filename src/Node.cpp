// src/Node.cpp
/**
 * @file        Node.cpp
 * @description Implements the Node class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 */

#include "../include/Node.hpp"

// Constructor
Node::Node(const string& data) {
    this->data = data;
    this->next = nullptr;
    this->root = nullptr;

    // Build BST from data
    for(char c : data) {
        insertToTree(c);
    }
    calculateTreeValue();
}

// Destructor
Node::~Node() {
    deleteTree(root);
}

// Getters
string Node::getData() const {
    return data;
}

int Node::getTreeValue() const {
    return treeValue;
}

Node* Node::getNext() const {
    return next;
}

// Setters
void Node::setNext(Node* node) {
    next = node;
}

// Insert a character into BST
void Node::insertToTree(char c) {
    TreeNode* newNode = new TreeNode(c);

    if (!root) {
        root = newNode;
        return;
    }

    TreeNode* currentNode = root;
    while (true) {
        if (c < currentNode->getData()) {
            if (!currentNode->getLeft()) {
                currentNode->setLeft(newNode);
                break;
            }
            currentNode = currentNode->getLeft();
        } else {
            if (!currentNode->getRight()) {
                currentNode->setRight(newNode);
                break;
            }
            currentNode = currentNode->getRight();
        }
    }
}

// Calculate the total tree value
void Node::calculateTreeValue() {
    if (!root) {
        treeValue = 0;
        return;
    }

    int sumLeft = calculateSubtreeValue(root->getLeft());
    int sumRight = calculateSubtreeValue(root->getRight());
    treeValue = 2 * sumLeft + sumRight;
}

// Sum subtree nodes' values
int Node::calculateSubtreeValue(TreeNode* node) {
    if (!node) return 0;

    int value = static_cast<int>(node->getData());
    return value + 
           calculateSubtreeValue(node->getLeft()) + 
           calculateSubtreeValue(node->getRight());
}

// Delete a subtree
void Node::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}