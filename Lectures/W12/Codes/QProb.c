#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7 // Size of the hash table

// Define a struct for each hash table slot
typedef struct {
    int key;      // Key stored in the slot
    int value;    // Value associated with the key
    int isEmpty;  // Flag to indicate if the slot is empty (1 = empty, 0 = occupied)
} HashSlot;

// Hash table array
HashSlot hashTable[TABLE_SIZE];

// Initialize the hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = 0;
        hashTable[i].value = 0;
        hashTable[i].isEmpty = 1; // Mark all slots as empty
    }
}

// Hash function: computes the hash index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key-value pair into the hash table using quadratic probing
void insert(int key, int value) {
    int hashVal = hashFunction(key); // Compute initial hash index
    int p = 0; // Probe count
    int probes = 0; // Count the number of probes
    while (p < TABLE_SIZE) {
        int i = (hashVal + p * p) % TABLE_SIZE; // Quadratic probing formula
        if (hashTable[i].isEmpty) { // Empty slot found
            hashTable[i].key = key;    // Store the key
            hashTable[i].value = value; // Store the associated value
            hashTable[i].isEmpty = 0; // Mark the slot as occupied
            probes++;
            printf("Inserted key %d with value %d at index %d after %d probes.\n", key, value, i, probes);
            return;
        }
        p++; // Increase probe count
        probes++;
    }
    printf("Hash table is full. Cannot insert key %d with value %d\n", key, value);
}

// Find a value associated with a key using quadratic probing
int find(int key) {
    int hashVal = hashFunction(key); // Compute the initial hash index
    int p = 0; // Probe count
    while (p < TABLE_SIZE) {
        int i = (hashVal + p * p) % TABLE_SIZE; // Quadratic probing formula
        if (hashTable[i].isEmpty) {
            return -1; // Empty cell found, key not in table
        }
        if (hashTable[i].key == key) {
            return hashTable[i].value; // Key found, return associated value
        }
        p++; // Move to the next cell
    }
    return -1; // Table fully traversed without finding the key
}

// Print the current state of the hash table
void printTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isEmpty) {
            printf("[%d]: Empty\n", i);
        } else {
            printf("[%d]: Key = %d, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }
    printf("\n");
}

// Main function to demonstrate the example
int main() {
    initTable(); // Initialize the hash table

    // Example insertions
    insert(76, 760); // Key = 76, Value = 760
    insert(40, 400); // Key = 40, Value = 400
    insert(48, 480); // Key = 48, Value = 480
    insert(5, 50);   // Key = 5, Value = 50
    insert(55, 550); // Key = 55, Value = 550

    // Print the final hash table
    printTable();

    // Search for a key and print its value
    int keyToFind = 48;
    int value = find(keyToFind);
    if (value != -1) {
        printf("Key %d found with value %d.\n", keyToFind, value);
    } else {
        printf("Key %d not found!\n", keyToFind);
    }
  return 0;
}
