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