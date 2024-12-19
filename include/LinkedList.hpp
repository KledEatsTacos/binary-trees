/**
 * @file        linkedlist.hpp
 * @description declares the LinkedList class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"
using namespace std;

class LinkedList {
private:
    Node* head;
    Node* current; //pointer to the current node, duh. it will be indicated by an arrow
    int size;

public:
    LinkedList();
    ~LinkedList();

    void addNode(const string& data);
    void displayNodes();
    void moveNext();          //press 'd' to move next
    void movePrev();          //press 'a' to move previous
    void deleteCurrentNode(); //press 's' to delete current node
    Node* getCurrentNode() const;
};

#endif