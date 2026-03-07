# Directories
SRC_DIR = src
TARGET_DIR = target

# Tools and Flags
CC = g++
CFLAGS = -g -w -std=c++14
# Add the target dir to include path so main.cc can find generated headers
INCLUDES = -I$(SRC_DIR) -I$(TARGET_DIR)

# Files
# Automatically find all .cpp files in src (e.g., SymbolTable.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Convert those .cpp paths to .o paths in the target directory
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(TARGET_DIR)/%.o)

# The final executable
EXE = $(TARGET_DIR)/compiler

# Main Targets
all: $(TARGET_DIR) $(EXE)

# Link everything together
$(EXE): $(TARGET_DIR)/lex.yy.c $(TARGET_DIR)/parser.tab.o $(OBJS) $(SRC_DIR)/main.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXE) $(TARGET_DIR)/parser.tab.o $(TARGET_DIR)/lex.yy.c $(OBJS) $(SRC_DIR)/main.cc 

# Rule for Bison (Parser)
$(TARGET_DIR)/parser.tab.cc: $(SRC_DIR)/parser.yy
	bison -d -o $(TARGET_DIR)/parser.tab.cc $(SRC_DIR)/parser.yy 

# Rule for Flex (Lexer)
$(TARGET_DIR)/lex.yy.c: $(SRC_DIR)/lexer.flex $(TARGET_DIR)/parser.tab.cc
	flex -o $(TARGET_DIR)/lex.yy.c $(SRC_DIR)/lexer.flex 

# Rule for the Parser object file
$(TARGET_DIR)/parser.tab.o: $(TARGET_DIR)/parser.tab.cc
	$(CC) $(CFLAGS) $(INCLUDES) -c $(TARGET_DIR)/parser.tab.cc -o $(TARGET_DIR)/parser.tab.o 

# Pattern Rule for all other .cpp to .o conversions
$(TARGET_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

# Create target directory if it doesn't exist
$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# Graphviz tree generation
tree: 
	dot -Tpdf tree.dot -o $(TARGET_DIR)/tree.pdf 

# Clean up
clean:
	rm -rf $(TARGET_DIR) 

.PHONY: all clean tree
