CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS =

SRC_DIR = src
OBJ_DIR = lib
BIN_DIR = bin

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/LinkedList.cpp $(SRC_DIR)/Node.cpp $(SRC_DIR)/TreeNode.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/LinkedList.o $(OBJ_DIR)/Node.o $(OBJ_DIR)/TreeNode.o
EXEC = $(BIN_DIR)/program.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	$(EXEC)

clean:
	del /Q "$(OBJ_DIR)\*.o" "$(BIN_DIR)\*.exe"

.PHONY: all run clean