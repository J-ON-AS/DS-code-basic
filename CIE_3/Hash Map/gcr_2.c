#include<stdio.h>
#include<stdlib.h>

// Global variables
int *ht, size; // Pointer for hash table and variable for the size of the hash table
int count = 0; // Counter for number of elements in the hash table

// Function to initialize the hash table
void initHashTable() {
    ht = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        ht[i] = -1; // Initialize each slot with -1 indicating an empty slot
    }
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = key % size;
    while(ht[index] != -1) {
        index = (index + 1) % size; // Linear probing to find an empty slot
    }
    ht[index] = key; // Insert the key into the hash table
    count++; // Increment the counter
}

// Function to display the contents of the hash table
void display() {
    if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }
    printf("\nHash Table contents are:\n ");
    for(int i = 0; i < size; i++) {
        printf("\n T[%d] --> %d ", i, ht[i]);
    }
}

// Main function
int main() {
    int n;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the size of the hash table: ");
    scanf("%d", &size);

    initHashTable(); // Initialize the hash table

    int key;
    printf("\nEnter the key values for N Employee Records:\n ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        if(count == size) {
            printf("\n~~~Hash table is full. Cannot insert the record %d key~~~", i+1);
            break;
        }
        insert(key); // Insert keys into the hash table
    }

    display(); // Display the hash table contents
    return 0;
}
