#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000 // Maximum number of employees
#define HT_SIZE 100 // Size of the hash table
#define KEY_DIGITS 4 // Number of digits in the key
#define ADDR_DIGITS 2 // Number of digits in the address

struct Employee {
    int key;
    // Add other employee information here
    struct Employee* next; // For separate chaining
};

struct HashTable {
    struct Employee* table[HT_SIZE];
};

int hashFunction(int key) {
    return key % HT_SIZE;
}

// Separate Chaining - Insert
void insertEmployeeSeparateChaining(struct HashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);
    if (ht->table[index] == NULL) {
        ht->table[index] = emp;
        emp->next = NULL;
    } else {
        struct Employee* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = emp;
        emp->next = NULL;
    }
}

// Separate Chaining - Search
struct Employee* searchEmployeeSeparateChaining(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Employee* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Linear Probing - Insert
void insertEmployeeLinearProbing(struct HashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);
    while (ht->table[index] != NULL) {
        index = (index + 1) % HT_SIZE;
    }
    ht->table[index] = emp;
}

// Linear Probing - Search
struct Employee* searchEmployeeLinearProbing(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }
        index = (index + 1) % HT_SIZE;
    }
    return NULL;
}

// Quadratic Probing - Insert
void insertEmployeeQuadraticProbing(struct HashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);
    int i = 1;
    while (ht->table[index] != NULL) {
        index = (index + i * i) % HT_SIZE;
        i++;
    }
    ht->table[index] = emp;
}

// Quadratic Probing - Search
struct Employee* searchEmployeeQuadraticProbing(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int i = 1;
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }
        index = (index + i * i) % HT_SIZE;
        i++;
    }
    return NULL;
}

// Double Hashing - Insert
void insertEmployeeDoubleHashing(struct HashTable* ht, struct Employee* emp) {
    int index = hashFunction(emp->key);
    int hash2 = 1 + (emp->key % (HT_SIZE - 1));
    while (ht->table[index] != NULL) {
        index = (index + hash2) % HT_SIZE;
    }
    ht->table[index] = emp;
}

// Double Hashing - Search
struct Employee* searchEmployeeDoubleHashing(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int hash2 = 1 + (key % (HT_SIZE - 1));
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }
        index = (index + hash2) % HT_SIZE;
    }
    return NULL;
}

int main() {
    struct HashTable htSeparateChaining, htLinearProbing, htQuadraticProbing, htDoubleHashing;
    int i;
    
    // Initialize hash tables
    for (i = 0; i < HT_SIZE; i++) {
        htSeparateChaining.table[i] = NULL;
        htLinearProbing.table[i] = NULL;
        htQuadraticProbing.table[i] = NULL;
        htDoubleHashing.table[i] = NULL;
    }

    // Example: Inserting some employees
    struct Employee employees[MAX_EMPLOYEES];
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        employees[i].key = rand() % 10000; // Generating random 4-digit keys
        insertEmployeeSeparateChaining(&htSeparateChaining, &employees[i]);
        insertEmployeeLinearProbing(&htLinearProbing, &employees[i]);
        insertEmployeeQuadraticProbing(&htQuadraticProbing, &employees[i]);
        insertEmployeeDoubleHashing(&htDoubleHashing, &employees[i]);
    }

    // Example: Searching for an employee
    int searchKey = employees[rand() % MAX_EMPLOYEES].key; // Randomly choosing a key

    // Separate Chaining
    struct Employee* foundEmployeeSeparateChaining = searchEmployeeSeparateChaining(&htSeparateChaining, searchKey);
    if (foundEmployeeSeparateChaining != NULL) {
        printf("Employee found with key %d using Separate Chaining\n", searchKey);
    } else {
        printf("Employee not found with key %d using Separate Chaining\n", searchKey);
    }

    // Linear Probing
    struct Employee* foundEmployeeLinearProbing = searchEmployeeLinearProbing(&htLinearProbing, searchKey);
    if (foundEmployeeLinearProbing != NULL) {
        printf("Employee found with key %d using Linear Probing\n", searchKey);
    } else {
        printf("Employee not found with key %d using Linear Probing\n", searchKey);
    }

    // Quadratic Probing
    struct Employee* foundEmployeeQuadraticProbing = searchEmployeeQuadraticProbing(&htQuadraticProbing, searchKey);
    if (foundEmployeeQuadraticProbing != NULL) {
        printf("Employee found with key %d using Quadratic Probing\n", searchKey);
    } else {
        printf("Employee not found with key %d using Quadratic Probing\n", searchKey);
    }

    // Double Hashing
    struct Employee* foundEmployeeDoubleHashing = searchEmployeeDoubleHashing(&htDoubleHashing, searchKey);
    if (foundEmployeeDoubleHashing != NULL) {
        printf("Employee found with key %d using Double Hashing\n", searchKey);
    } else {
        printf("Employee not found with key %d using Double Hashing\n", searchKey);
    }

    return 0;
}
