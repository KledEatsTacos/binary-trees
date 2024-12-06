/**
 * @file        main.cpp
 * @description The main file of the program.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/LinkedList.hpp"
#include <fstream>
#include <iostream>

int main() {
    LinkedList list;
    string line;
    
    //reads from file
    ifstream file("agaclar.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    //creates nodes from each line
    while (getline(file, line)) {
        list.addNode(line);
    }
    file.close();

    //displays the nodes
    list.displayNodes();

    //this is the user input where the user can move between or delete nodes
    char input;
    while (true) {
        cout << "\nEnter command (a:previous, d:next, s:delete): ";
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
        }
        
        system("cls");
        list.displayNodes();
    }

    return 0;
}