/**
 * @file        TreeNode.cpp
 * @description implements the TreeNode class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/LinkedList.hpp"
#include <iostream>
using namespace std;

//I wanted to use the <algorithm> library but i didn't know if it's allowed or not
//so I created my own function.
int min(int a, int b) {
    return (a < b) ? a : b;
}

LinkedList::LinkedList() {
    head = nullptr;
    current = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->getNext();
        delete temp;
        temp = next;
    }
}

void LinkedList::addNode(const string& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        current = head;
    } else {
        Node* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    size++;
}

void LinkedList::displayNodes() {
    if (!head) {
        cout << "\nNo nodes left!\n";
        return;
    }

    //find current node position
    Node* temp = head;
    int currentNodePosition = 0;

    //handle case when current is nullptr
    if (!current) {
        current = head;
    }

    while (temp != current && temp != nullptr) {
        currentNodePosition++;
        temp = temp->getNext();
    }

    //calculate which page we're on (0-based)
    int startPosition = (currentNodePosition / 10) * 10;

    //find the starting node of the current page
    Node* displayStart = head;
    for (int i = 0; i < startPosition && displayStart != nullptr; i++) {
        displayStart = displayStart->getNext();
    }

    //display page information
    cout << "\nDisplaying nodes " << startPosition + 1
         << " to " << min(startPosition + 10, size)
         << " (Total: " << size << ")\n\n";

    //display up to 10 nodes from starting position
    temp = displayStart;
    int count = 0;
    while (temp && count < 10) {
        cout << "Address: " << temp;
        if (temp == current) cout << " <-- Current";
        cout << "\nTree Value: " << temp->getTreeValue();
        cout << "\nNext Address: " << temp->getNext() << "\n\n";
        temp = temp->getNext();
        count++;
    }
}

void LinkedList::moveNext() {
    if (current && current->getNext()) {
        current = current->getNext();
    }
}

void LinkedList::movePrev() {
    if (current != head) {
        Node* temp = head;
        while (temp->getNext() != current && temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        current = temp;
    }
}

void LinkedList::deleteCurrentNode() {
    if (!current) return;

    //for deleting head node
    if (current == head) {
        head = current->getNext();
        delete current;
        current = head;
        size--;
    } else {
        //find the previous node
        Node* prev = head;
        while (prev && prev->getNext() != current) {
            prev = prev->getNext();
        }

        if (prev) {
            prev->setNext(current->getNext());
            delete current;
            current = prev->getNext() ? prev->getNext() : prev;
            size--;
        }
    }

    //if you delete all nodes
    if (head == nullptr) {
        current = nullptr;
    }
}

Node* LinkedList::getCurrentNode() const {
    return current;
}