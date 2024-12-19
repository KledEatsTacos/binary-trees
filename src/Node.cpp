/**
 * @file        Node.cpp
 * @description implements the Node class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author       Mustafa Masri.
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

int Node::getHeight(TreeNode* node) const {
    if (!node) return 0;
    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void Node::printSpaces(int count) const {
    for (int i = 0; i < count; ++i) {
        cout << " ";
    }
}

void Node::displayLevel(TreeNode* node, int level, int spacing, TreeDisplayBuffer& buffer) const {
    if (level == 1) {
        if (node) {
            printSpaces(spacing);
            cout << node->getData();
            printSpaces(spacing);
        } else {
            printSpaces(spacing * 2 + 1);
        }
    } else if (level > 1) {
        if (node) {
            displayLevel(node->getLeft(), level - 1, spacing / 2, buffer);
            displayLevel(node->getRight(), level - 1, spacing / 2, buffer);
        } else {
            displayLevel(nullptr, level - 1, spacing / 2, buffer);
            displayLevel(nullptr, level - 1, spacing / 2, buffer);
        }
    }
}

void Node::displayTree() const {
    if (!root) {
        cout << "Empty Tree" << endl;
        return;
    }

    int height = getHeight(root);
    // Use height+0.5 for middle ground spacing
    int width = (1 << (height + 1)) / 1.5; 
    int totalHeight = height * 2;
    
    TreeDisplayBuffer buffer(totalHeight, width);
    fillBuffer(root, 0, 0, width - 1, buffer);
    drawConnections(root, 0, 0, width - 1, buffer);
    
    cout << endl;
    buffer.print();
    cout << endl;
}

void Node::fillBuffer(TreeNode* node, int level, int left, int right, TreeDisplayBuffer& buffer) const {
    if (!node) return;

    int mid = (left + right) / 2;
    buffer.setChar(level * 2, mid, node->getData());

    if (node->getLeft())
        fillBuffer(node->getLeft(), level + 1, left, mid - 1, buffer);
    if (node->getRight())
        fillBuffer(node->getRight(), level + 1, mid + 1, right, buffer);
}

void Node::drawConnections(TreeNode* node, int level, int left, int right, TreeDisplayBuffer& buffer) const {
    if (!node) return;

    int mid = (left + right) / 2;
    
    if (node->getLeft()) {
        int childMid = (left + mid - 1) / 2;
        for (int i = childMid; i <= mid; i++)
            buffer.setChar(level * 2 + 1, i, '.');
    }

    if (node->getRight()) {
        int childMid = (mid + 1 + right) / 2;
        for (int i = mid; i <= childMid; i++)
            buffer.setChar(level * 2 + 1, i, '.');
    }

    drawConnections(node->getLeft(), level + 1, left, mid - 1, buffer);
    drawConnections(node->getRight(), level + 1, mid + 1, right, buffer);
}

void Node::mirrorTree() {
    mirrorSubtree(root);
}

void Node::mirrorSubtree(TreeNode* node) {
    if (!node) return;

    // Swap children
    TreeNode* temp = node->getLeft();
    node->setLeft(node->getRight());
    node->setRight(temp);

    // Recursively mirror subtrees
    mirrorSubtree(node->getLeft());
    mirrorSubtree(node->getRight());
}