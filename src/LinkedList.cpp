// src/LinkedList.cpp
/**
 * @file        LinkedList.cpp
 * @description Implements the LinkedList class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 */

#include "../include/LinkedList.hpp"
#include <iostream>
#include <algorithm> // For std::min

using namespace std;

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
    current = nullptr;
    size = 0;
}

// Destructor
LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->getNext();
        delete temp;
        temp = next;
    }
}

// Add a new node to the end of the list
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

// Display nodes with pagination (10 nodes per page)
void LinkedList::displayNodes() {
    if (!head) {
        cout << "\nList is empty.\n";
        return;
    }

    // Find current node position
    Node* temp = head;
    int currentNodePosition = 0;
    while (temp != current && temp != nullptr) {
        currentNodePosition++;
        temp = temp->getNext();
    }

    // Calculate which page we're on (0-based)
    int startPosition = (currentNodePosition / 10) * 10;

    // Find the starting node of the current page
    Node* displayStart = head;
    for (int i = 0; i < startPosition && displayStart != nullptr; i++) {
        displayStart = displayStart->getNext();
    }

    // Display page information
    cout << "\nDisplaying nodes " << startPosition + 1 
         << " to " << min(startPosition + 10, size) 
         << " (Total: " << size << ")\n\n";

    // Display up to 10 nodes from starting position
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

// Move to the next node
void LinkedList::moveNext() {
    if (current && current->getNext()) {
        current = current->getNext();
    }
}

// Move to the previous node
void LinkedList::movePrev() {
    if (current != head) {
        Node* temp = head;
        while (temp->getNext() != current && temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        current = temp;
    }
}

// Delete the current node
void LinkedList::deleteCurrentNode() {
    if (!current) return;

    // If deleting head node
    if (current == head) {
        head = current->getNext();
        delete current;
        current = head;
        size--;
        return;
    }

    // Find the previous node
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

// Get the current node
Node* LinkedList::getCurrentNode() const {
    return current;
}