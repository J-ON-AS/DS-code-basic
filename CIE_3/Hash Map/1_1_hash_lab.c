#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the bool type

#define MAX_EMPLOYEES 1000 // Maximum number of employees
#define HT_SIZE 100 // Size of the hash table
#define KEY_DIGITS 4 // Number of digits in the key
#define ADDR_DIGITS 2 // Number of digits in the address

struct Employee {
    int key;
    // Add other employee information here
};

struct HashTable {
    struct Employee* table[HT_SIZE];
};

int hashFunction(int key) {
    return key % HT_SIZE;
}

void insertEmployee(struct HashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);

    // Linear probing to resolve collisions
    while (ht->table[index] != NULL) {
        index = (index + 1) % HT_SIZE;
    }

    ht->table[index] = emp;
}

struct Employee* searchEmployee(struct HashTable* ht, int key) {
    int index = hashFunction(key);

    // Linear probing to find the employee
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }
        index = (index + 1) % HT_SIZE;
    }

    return NULL; // Employee not found
}

bool isKeyUsed(struct HashTable* ht, int key) {
    int index = hashFunction(key);

    // Linear probing to find if the key is already used
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return true;
        }
        index = (index + 1) % HT_SIZE;
    }

    return false; // Key is not used
}

int main() {
    struct HashTable ht;
    int i;
    bool keyUsed[MAX_EMPLOYEES] = {false}; // Array to keep track of used keys

    // Initialize hash table
    for (i = 0; i < HT_SIZE; i++) {
        ht.table[i] = NULL;
    }

    // Example: Inserting some employees
    struct Employee employees[MAX_EMPLOYEES];
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        int newKey;
        do {
            newKey = rand() % 10000; // Generate a new random key
        } while (isKeyUsed(&ht, newKey)); // Check if the key is already used

        employees[i].key = newKey;
        insertEmployee(&ht, &employees[i]);
    }

    // Example: Searching for an employee
    int searchKey = employees[rand() % MAX_EMPLOYEES].key; // Randomly choosing a key
    struct Employee* foundEmployee = searchEmployee(&ht, searchKey);
    if (foundEmployee != NULL) {
        printf("Employee found with key %d\n", searchKey);
    } else {
        printf("Employee not found with key %d\n", searchKey);
    }

    return 0;
}
