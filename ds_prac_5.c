#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // size of hash table

int hashTable[SIZE];

// initialize hash table with -1 (empty)
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// simple hash function
int hash(int key) {
    return key % SIZE;
}

// insert a key using linear probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i == SIZE)
        printf("Hash table is full! Cannot insert %d\n", key);
    else {
        hashTable[(index + i) % SIZE] = key;
        printf("%d inserted at index %d\n", key, (index + i) % SIZE);
    }
}

// search for a key
void search(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i) % SIZE] == key) {
            printf("%d found at index %d\n", key, (index + i) % SIZE);
            return;
        }
        i++;
    }
    printf("%d not found in the hash table.\n", key);
}

// display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] == -1)
            printf("empty\n");
        else
            printf("%d\n", hashTable[i]);
    }
}

int main() {
    int choice, key;

    init();

    while (1) {
        printf("\n--- HASHING MENU ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
