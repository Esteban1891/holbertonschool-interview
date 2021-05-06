# 0x02. Heap Insert
## Requirements
### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you dont have to push them to your repo (if you do we wont take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called binary_trees.h
- Dont forget to push your header file
- All your header files should be include guarded

## Tasks
#### 0. New node
Write a function that creates a binary tree node:
- Prototype: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
- parent is a pointer to the parent node of the node to create
- value is the value to put in the new node
- When created, a node does not have any children
- Your function must return a pointer to the new node, or NULL on failure

#### 1. Heap - Insert
Write a function that inserts a value into a Max Binary Heap:
- Prototype: heap_t *heap_insert(heap_t **root, int value)
- root is a double pointer to the root node of the Heap
- value is the value store in the node to be inserted
- Your function must return a pointer to the inserted node, or NULL on failure
- If the address stored in root is NULL, the created node must become the root node.
- You have to respect a Max Heap ordering
- You are allowed to have up to 6 functions in your file
#### Twitter: [Jorge Chaux Jr](https://twitter.com/jorgechauxjr)
