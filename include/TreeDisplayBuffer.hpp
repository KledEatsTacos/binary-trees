/**
 * @file        TreeDisplayBuffer.hpp
 * @description declares the TreeDisplayBuffer class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-19.
 * @author      Mustafa Masri.
 */

//this is a replacement class for vector since we are not allowed to use it

#ifndef TREEDISPLAYBUFFER_HPP
#define TREEDISPLAYBUFFER_HPP

class TreeDisplayBuffer {
private:
    char* data;
    int capacity;
    int size;
    int width;
    int height;

    void resize(int newCapacity);
    int getIndex(int row, int col) const;

public:
    TreeDisplayBuffer(int initialHeight, int initialWidth);
    ~TreeDisplayBuffer();

    void setChar(int row, int col, char c);
    char getChar(int row, int col) const;
    void clear();
    void print() const;
    void ensureCapacity(int rows, int cols);
};

#endif