#include "../include/TreeDisplayBuffer.hpp"
#include <iostream>

using namespace std;

TreeDisplayBuffer::TreeDisplayBuffer(int initialHeight, int initialWidth) {
    height = initialHeight;
    width = initialWidth;
    capacity = height * width;
    size = 0;
    data = new char[capacity];
    clear();
}

TreeDisplayBuffer::~TreeDisplayBuffer() {
    delete[] data;
}

void TreeDisplayBuffer::resize(int newCapacity) {
    char* newData = new char[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

int TreeDisplayBuffer::getIndex(int row, int col) const {
    return row * width + col;
}

void TreeDisplayBuffer::setChar(int row, int col, char c) {
    int index = getIndex(row, col);
    if (index >= capacity) {
        resize(capacity * 2);
    }
    data[index] = c;
    size = (index >= size) ? index + 1 : size;
}

char TreeDisplayBuffer::getChar(int row, int col) const {
    return data[getIndex(row, col)];
}

void TreeDisplayBuffer::clear() {
    for (int i = 0; i < capacity; i++) {
        data[i] = ' ';
    }
}

void TreeDisplayBuffer::print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << getChar(i, j);
        }
        cout << endl;
    }
}