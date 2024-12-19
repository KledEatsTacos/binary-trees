//file:         TreeDisplayBuffer.cpp
//description:  implements the TreeDisplayBuffer class.
//course:       2. A.
//assignment:   Assignment 2.
//date:         2024-12-19.
//author:       Mustafa Masri.

#include "../include/TreeDisplayBuffer.hpp"
#include <iostream>

using namespace std;

//constructor creates a buffer with given dimensions and initializes it with spaces
TreeDisplayBuffer::TreeDisplayBuffer(int initialHeight, int initialWidth) {
    height = initialHeight;
    width = initialWidth;
    capacity = height * width;
    size = 0;
    data = new char[capacity];
    clear();
}

//destructor frees the dynamically allocated memory
TreeDisplayBuffer::~TreeDisplayBuffer() {
    delete[] data;
}

//increases the buffer size when needed
void TreeDisplayBuffer::resize(int newCapacity) {
    char* newData = new char[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

//converts 2D coordinates to 1D array index
int TreeDisplayBuffer::getIndex(int row, int col) const {
    return row * width + col;
}

//places a character at the specified position, resizes if needed
void TreeDisplayBuffer::setChar(int row, int col, char c) {
    int index = getIndex(row, col);
    if (index >= capacity) {
        resize(capacity * 2);
    }
    data[index] = c;
    size = (index >= size) ? index + 1 : size;
}

//retrieves the character at the specified position
char TreeDisplayBuffer::getChar(int row, int col) const {
    return data[getIndex(row, col)];
}

//fills the entire buffer with spaces
void TreeDisplayBuffer::clear() {
    for (int i = 0; i < capacity; i++) {
        data[i] = ' ';
    }
}

//displays the buffer contents to console
void TreeDisplayBuffer::print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << getChar(i, j);
        }
        cout << endl;
    }
}