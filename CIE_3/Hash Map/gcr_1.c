#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Structure for product
typedef struct {
    int code;
    int memoryAddress;
} Product;

// Hash table
Product hashTable[SIZE];

// Hash function using remainder method
int hash(int key) {
    return key % SIZE;
}

// Insert a product into the hash table
void insert(int code, int memoryAddress) {
    int index = hash(code);
    int i = 0;

    while (hashTable[index].code != -1) {
        // Perform linear probing
        index = (index + 1) % SIZE;
        i++;

        // If all slots are full, exit
        if (i == SIZE) {
            printf("Hash table is full. Unable to insert product.\n");
            return;
        }
    }

    // Insert the product
    hashTable[index].code = code;
    hashTable[index].memoryAddress = memoryAddress;
    printf("Product with code %d inserted at memory address %d.\n", code, memoryAddress);
}

// Search for a product in the hash table
void search(int code) {
    int index = hash(code);
    int i = 0;

    while (hashTable[index].code != code) {
        // Perform linear probing
        index = (index + 1) % SIZE;
        i++;

        // If all slots are checked, exit
        if (hashTable[index].code == -1 || i == SIZE) {
            printf("Product with code %d not found in the hash table.\n", code);
            return;
        }
    }

    // Product found
    printf("Product with code %d found at memory address %d.\n", code, hashTable[index].memoryAddress);
}

// Main function
int main() {
    // Initialize the hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].code = -1;
        hashTable[i].memoryAddress = -1;
    }

    // Insert products into the hash table
    insert(1234, 1000);
    insert(1234, 1000);
    insert(5678, 2000);
    insert(9012, 3000);

    // Search for products in the hash table
    int choice, code;
    do {
        printf("\nMenu:\n");
        printf("1. Search for a product\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product code to search: ");
                scanf("%d", &code);
                search(code);
                break;
            case 2:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 2);

    return 0;
}
