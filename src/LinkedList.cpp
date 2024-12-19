/**
 * @file        LinkedList.cpp
 * @description implements the LinkedList class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/LinkedList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//I wanted to use the <algorithm> library to use min function but i didn't know if it's allowed or not
//so I created my own function.
//I am very smart.
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

//this part... THIS PART... THIS PART... THIS PART.. AAAAAAAAA
void LinkedList::displayNodes() {
    if (!head) {
        cout << "\nNo nodes left!\n";
        return;
    }

    //find current page based on current node position
    Node* temp = head;
    int currentPos = 0;
    while (temp && temp != current) {
        currentPos++;
        temp = temp->getNext();
    }

    //calculate start of page
    int startPos = (currentPos / 10) * 10;
    Node* displayStart = head;
    for (int i = 0; i < startPos && displayStart; i++) {
        displayStart = displayStart->getNext();
    }

    cout << "\nDisplaying nodes " << startPos + 1 
         << " to " << min(startPos + 10, size) 
         << " (Total: " << size << ")\n\n";

    //print top borders
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "+----------+";
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;

    //print addresses
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| " << hex << temp << dec << " |";
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;

    //print values
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| " << setw(8) << left << temp->getTreeValue() << " |";
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;

    //print next pointers
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| ";
        if (temp->getNext()) {
            cout << hex << temp->getNext() << dec;
        } else {
            cout << "NULL    ";
        }
        cout << " |";
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;

    //print bottom borders
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "+----------+";
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;

    //print current marker
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        if (temp == current) {
            cout << "     ^     ";
        } else {
            cout << "           ";
        }
        if (temp->getNext() && i < 9) cout << "  ";
        temp = temp->getNext();
    }
    cout << endl;
        if (current) {
        cout << "\nCurrent Tree Structure:\n\n";
        current->displayTree();
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