## :memo: Find the loop
\[ [Back](../../..#readme) \]
\[ [Example](#Example) \]
\[ [Files](#Files) \]

#### Reference

**Data Structures**
```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;
```
**Print function**
To match the examples in the tasks, you are given [this function](https://raw.githubusercontent.com/holbertonschool/0x1C.c/master/binary_tree_print.c)

**Task**
Write a function that checks if a binary tree is a valid [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree)
- Prototype: int binary_tree_is_avl(const binary_tree_t \*tree);
- Where tree is a pointer to the root node of the tree to check
- Your function must return 1 if tree is a valid AVL Tree, and 0 otherwise
- If tree is NULL, return 0

Properties of an AVL Tree:
- An AVL Tree is a BST
- The difference between heights of left and right subtrees cannot be more than one
- The left and right subtree each must also be a binary search tree

Note: In order for the main file to compile, you are provided with [this static library](https://s3.amazonaws.com/intranet-projects-files/interviews/484/libavl.a). This library wont be used during correction, its only purpose is for testing.

#### Example:
```bash
alex@/tmp/binary_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 10);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int avl;

    root = basic_tree();

    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);
    avl = binary_tree_is_avl(root->left);
    printf("Is %d avl: %d\n", root->left->n, avl);

    root->right->left = binary_tree_node(root->right, 97);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);

    root = basic_tree();
    root->right->right->right = binary_tree_node(root->right->right, 430);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);

    root->right->right->right->left = binary_tree_node(root->right->right->right, 420);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
alex@/tmp/binary_trees$ ./0-is_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
alex@/tmp/binary_trees$
```

#### Files:
\[ [0-binary_tree_is_avl.c](0-binary_tree_is_avl.c) \]

\[ [Back](../../..#readme) \]
