/**
 * @file        main.cpp
 * @description the main file of the program.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author       Mustafa Masri.
 */

#include "../include/LinkedList.hpp"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    string line;

    //read from file
    ifstream file("agaclar.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    //create nodes from each line
    while (getline(file, line)) {
        list.addNode(line);
    }
    file.close();

    //display the nodes
    list.displayNodes();

    //user input loop
    char input;
    while (true) {
        cout << "\nEnter command (a:previous, d:next, s:delete, w:mirror, q:quit): ";
        cin >> input;

        switch (input) {
            case 'a':
            case 'A':
                list.movePrev();
                break;
            case 'd':
            case 'D':
                list.moveNext();
                break;
            case 's':
            case 'S':
                list.deleteCurrentNode();
                break;
            case 'w':
            case 'W':
                if (list.getCurrentNode()) {
                    list.getCurrentNode()->mirrorTree();
                }
                break;
            case 'q':
            case 'Q':
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid command." << endl;
                break;
        }

        system("cls"); //clear the console so that it doesn't fill up
        list.displayNodes();
    }

    return 0;
}