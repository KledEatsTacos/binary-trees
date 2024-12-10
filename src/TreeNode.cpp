/**
 * @file        TreeNode.cpp
 * @description implements the TreeNode class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/TreeNode.hpp"

TreeNode::TreeNode(char c) {
    data = c;
    left = nullptr;
    right = nullptr;
}

TreeNode::~TreeNode() {}

char TreeNode::getData() const {
    return data;
}

TreeNode* TreeNode::getLeft() const {
    return left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

void TreeNode::setLeft(TreeNode* node) {
    left = node;
}

void TreeNode::setRight(TreeNode* node) {
    right = node;
}