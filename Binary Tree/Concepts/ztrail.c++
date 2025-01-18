#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;       // Pointer to the underlying array
    int size;        // Number of elements currently in the vector
    int capacity;    // Capacity of the underlying array
} Vector;

// Function to initialize the vector
void initVector(Vector *vector, int initialCapacity) {
    vector->size = 0;
    vector->capacity = initialCapacity;
    vector->data = (int *)malloc(sizeof(int) * vector->capacity);
    if (vector->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

// Function to insert an element into the vector
void insertVector(Vector *vector, int element) {
    // Check if resizing is needed
    if (vector->size == vector->capacity) {
        vector->capacity *= 2; // Double the capacity
        vector->data = (int *)realloc(vector->data, sizeof(int) * vector->capacity);
        if (vector->data == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    vector->data[vector->size++] = element;
}

// Function to get the element at a specific index
int getVector(Vector *vector, int index) {
    if (index < 0 || index >= vector->size) {
        printf("Index out of bounds.\n");
        exit(1);
    }
    return vector->data[index];
}

// Function to free the allocated memory
void freeVector(Vector *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

int main() {
    Vector vector;

    // Initialize the vector with an initial capacity of 4
    initVector(&vector, 4);

    // Insert elements into the vector
    for (int i = 0; i < 10; i++) {
        insertVector(&vector, i * 10);
    }

    // Print the elements in the vector
    for (int i = 0; i < vector.size; i++) {
        printf("%d ", getVector(&vector, i));
    }
    printf("\n");

    // Free the vector's memory
    freeVector(&vector);

    return 0;
}
