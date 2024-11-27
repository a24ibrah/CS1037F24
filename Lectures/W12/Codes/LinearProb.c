#include <stdio.h>
#include <stdlib.h>

#define N 10 // Size of the hash table

typedef struct {
    int key;       // The key
    int value;     // The value
    int isEmpty;   // 1 if empty, 0 otherwise
} HashEntry;

// Hash table array
HashEntry hashTable[N];

// Initialize the hash table
void initTable() {
    for (int i = 0; i < N; i++) {
        hashTable[i].key = 0;
        hashTable[i].value = 0;
        hashTable[i].isEmpty = 1; // Mark all cells as empty
    }
}

// Hash function
int hashFunction(int key) {
    return key % N;
}

// Insert function using linear probing
void insert(int key, int value) {
    int hashVal = hashFunction(key); // Compute initial hash index
    int p = 0; // Probe count
    while (p < N) {
        int i = (hashVal + p) % N; // Linear probing
        if (hashTable[i].isEmpty) { // If the slot is empty
            hashTable[i].key = key;
            hashTable[i].value = value;
            hashTable[i].isEmpty = 0; // Mark the slot as occupied
            printf("Inserted key %d with value %d at index %d\n", key, value, i);
            return;
        }
        p++; // Move to the next cell
    }
    printf("Hash table is full. Cannot insert key %d with value %d\n", key, value);
}

// Find function using linear probing
HashEntry *find(int key) {
    int hashVal = hashFunction(key);
    int p = 0; // Probe count
    while (p < N) {
        int i = (hashVal + p) % N; // Linear probing
        HashEntry *entry = &hashTable[i];
        if (entry->isEmpty) {
            return NULL; // Empty cell found
        }
        if (entry->key == key) {
            return entry; // Key found
        }
        p++; // Move to the next cell
    }
    return NULL; // Full table probed without finding the key
}

int main() {
    initTable(); // Initialize the hash table

    // Example: Insert some data
    insert(13, 130); // Insert key 13 with value 130
    insert(25, 250); // Insert key 25 with value 250
    insert(33, 330); // Insert key 33 with value 330
    insert(43, 430); // Insert key 43 with value 430

    // Try to find a key
    int keyToFind = 33;
    HashEntry *result = find(keyToFind);

    if (result != NULL) {
        printf("Key %d found with value: %d\n", keyToFind, result->value);
    } else {
        printf("Key %d not found!\n", keyToFind);
    }

    return 0;
}


