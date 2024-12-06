/**
 * @file        linkedlist.hpp
 * @description Declares the LinkedList class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.hpp"

class LinkedList {
private:
    Node* head;
    Node* current;  //when printing we will use arrows to point to which node we are at
    int size;

public:
    LinkedList();
    ~LinkedList();
    
    void addNode(const string& data);
    void displayNodes();
    void moveNext();                       //this will be done by pressing D
    void movePrev();                       //this will be done by pressing A
    void deleteCurrentNode();              //this will be done by pressing S
    Node* getCurrentNode() const;
};

#endif