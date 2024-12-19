/**
 * @file        TreeNode.hpp
 * @description Declares the TreeNode class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#ifndef TREENODE_HPP
#define TREENODE_HPP

class TreeNode {
private:
    char data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(char c);
    ~TreeNode();

    char getData() const;
    TreeNode* getLeft() const;
    TreeNode* getRight() const;
    void setLeft(TreeNode* node);
    void setRight(TreeNode* node);
};

#endif