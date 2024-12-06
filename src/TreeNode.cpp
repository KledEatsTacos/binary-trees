// src/TreeNode.cpp
/**
 * @file        TreeNode.cpp
 * @description Implements the TreeNode class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 */

#include "../include/TreeNode.hpp"

// Constructor
TreeNode::TreeNode(char c) {
    data = c;
    left = nullptr;
    right = nullptr;
}

// Destructor
TreeNode::~TreeNode() {
    delete left;
    delete right;
}

// Getters
char TreeNode::getData() const {
    return data;
}

TreeNode* TreeNode::getLeft() const {
    return left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

// Setters
void TreeNode::setLeft(TreeNode* node) {
    left = node;
}

void TreeNode::setRight(TreeNode* node) {
    right = node;
}