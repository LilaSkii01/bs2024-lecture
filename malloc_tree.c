#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
struct my_tree {
    int data;
    struct my_tree *left;
    struct my_tree *right;
};

int main() {
    // Dynamically allocate memory to create a tree node
    struct my_tree *p = malloc(sizeof(struct my_tree));
    
    // Check if memory allocation was successful
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the node's data and pointers
    p->data = 10;       // Set the node's data
    p->left = NULL;     // Left child is NULL
    p->right = NULL;    // Right child is NULL

    // Print the node's data
    printf("Node data: %d\n", p->data);

    // Free the allocated memory
    free(p);

    return 0;
}