#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TrieNode {
    struct TrieNode* children[26];
    int isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

//insert a key into the Trie
void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) continue;
        int index = tolower(key[i]) - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = 1;
}

//search a key in the Trie
int search(struct TrieNode* root, const char* key) {
    struct TrieNode* curr = root;
    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) continue;
        int index = tolower(key[i]) - 'a';
        if (curr->children[index] == NULL)
            return 0;
        curr = curr->children[index];
    }
    return curr != NULL && curr->isEndOfWord;
}

//read keys from a file
int readKeysFromFile(char keys[][30], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        return 0;
    }

    char buffer[512];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        int count = 0;
        char* token = strtok(buffer, "\t\n ");
        while (token != NULL && count < 50) {
            strcpy(keys[count++], token);
            token = strtok(NULL, "\t\n ");
        }
        fclose(file);
        return count;
    }

    fclose(file);
    return 0;
}

//search user input
void searchUserInput(struct TrieNode* root) {
    char userKey[30];
    printf("\nEnter key to search: ");
    scanf("%s", userKey);
    if (search(root, userKey))
        printf("%s is FOUND in the trie.\n", userKey);
    else
        printf("%s is NOT FOUND in the trie.\n", userKey);
}

int main() {
    struct TrieNode* root = createNode();

    printf("----------------------------\n");
    printf("     TRIE PROGRAM (C)       \n");
    printf("----------------------------\n");

    //search user input in file
    printf("\nPart (i): Reading keys from file...\n");
    char fileKeys[50][30];
    int fileCount = readKeysFromFile(fileKeys, "keys.txt");

    for (int i = 0; i < fileCount; i++)
        insert(root, fileKeys[i]);

    printf("Inserted %d keys from file into Trie.\n", fileCount);
    searchUserInput(root);

    //search user input
    printf("\nPart (ii): Reading keys from char array...\n");
    struct TrieNode* root2 = createNode();

    const char* keysArray[] = {
        "and", "bat", "ball", "book", "cot", "cotton",
        "internet", "interview", "joy", "job", "king",
        "lion", "man", "mango", "manage"
    };
    int n = sizeof(keysArray) / sizeof(keysArray[0]);

    for (int i = 0; i < n; i++)
        insert(root2, keysArray[i]);

    searchUserInput(root2);

    //search file input in array
    printf("\nPart (iii): Searching file keys inside array-based Trie...\n");
    for (int i = 0; i < fileCount; i++) {
        if (search(root2, fileKeys[i]))
            printf("%s -> FOUND\n", fileKeys[i]);
        else
            printf("%s -> NOT FOUND\n", fileKeys[i]);
    }

    printf("\nProgram completed.\n");
    return 0;
}
