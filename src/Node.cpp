/**
 * @file        Node.cpp
 * @description implements the Node class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/Node.hpp"

Node::Node(const string& data) {
    this->data = data;
    this->next = nullptr;
    this->root = nullptr;

    //build BST from data
    for (char c : data) {
        insertToTree(c);
    }
    calculateTreeValue();
}

Node::~Node() {
    deleteTree(root);
}

string Node::getData() const {
    return data;
}

int Node::getTreeValue() const {
    return treeValue;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* node) {
    next = node;
}

//insert character into BST
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

//calculate total tree value
void Node::calculateTreeValue() {
    if (!root) {
        treeValue = 0;
        return;
    }

    int rootValue = static_cast<int>(root->getData());
    int sumLeft = calculateSubtreeValue(root->getLeft(), true);
    int sumRight = calculateSubtreeValue(root->getRight(), false);
    treeValue = rootValue + sumLeft + sumRight;
}

//recursive helper function to calculate subtree values
int Node::calculateSubtreeValue(TreeNode* node, bool isLeft) {
    if (!node) return 0;

    int value = static_cast<int>(node->getData());

    //multiply by 2 if node is a left child
    if (isLeft) {
        value *= 2;
    }

    //recurse on children
    int leftSum = calculateSubtreeValue(node->getLeft(), true);
    int rightSum = calculateSubtreeValue(node->getRight(), false);

    return value + leftSum + rightSum;
}

void Node::deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->getLeft());
        deleteTree(node->getRight());
        delete node;
    }
}