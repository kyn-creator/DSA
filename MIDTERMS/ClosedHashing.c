#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10       // Table size
#define EMPTY -1     // Marks empty slot
#define DELETED -2   // Marks deleted slot

// -------------------------------
// HASH FUNCTION
// -------------------------------
int hashBrown(int elem) {
    int sum = 0;
    while (elem != 0) {
        sum += (elem % 10);  // add each digit
        elem /= 10;
    }
    return sum % MAX;  // bucket index
}

// -------------------------------
// INITIALIZATION
// -------------------------------
void initDictionary(int D[]) {
    for (int i = 0; i < MAX; ++i) {
        D[i] = EMPTY;  // initialize all slots to EMPTY
    }
}

// -------------------------------
// DISPLAY
// -------------------------------
void displayDict(int D[]) {
    printf("\n\tINDEX\tELEMENT\n");
    for (int i = 0; i < MAX; ++i) {
        printf("[%d]\t", i);
        if (D[i] == EMPTY) {
            printf("Empty");
        } else if (D[i] == DELETED) {
            printf("Deleted");
        } else {
            printf("%d", D[i]);
        }
        printf("\n");
    }
}

// -------------------------------
// SEARCH / MEMBERSHIP
// -------------------------------
bool isMember(int D[], int elem) {
    int key = hashBrown(elem);
    int start = key;  // remember start position

    while (D[key] != EMPTY) {
        if (D[key] == elem)
            return true;  // found

        key = (key + 1) % MAX;  // linear probing
        if (key == start)
            break;  // full loop
    }
    return false;  // not found
}

// -------------------------------
// INSERT UNIQUE ELEMENT
// -------------------------------
void insertUnique(int D[], int elem) {
    if (isMember(D, elem)) {
        printf("%d already exists in the table.\n", elem);
        return;
    }

    int key = hashBrown(elem);
    int start = key;

    while (D[key] != EMPTY && D[key] != DELETED) {
        key = (key + 1) % MAX;  // probe next slot
        if (key == start) {
            printf("Table is full. Cannot insert %d.\n", elem);
            return;
        }
    }

    D[key] = elem;
    printf("%d inserted at index %d.\n", elem, key);
}

// -------------------------------
// DELETE ELEMENT
// -------------------------------
void deleteMem(int D[], int elem) {
    int key = hashBrown(elem);
    int start = key;

    while (D[key] != EMPTY) {
        if (D[key] == elem) {
            D[key] = DELETED;  // mark as deleted
            printf("%d deleted from index %d.\n", elem, key);
            return;
        }

        key = (key + 1) % MAX;
        if (key == start)
            break;
    }

    printf("%d not found in the table.\n", elem);
}

// -------------------------------
// MAIN DRIVER
// -------------------------------
int main() {
    int D[MAX];
    initDictionary(D);

    insertUnique(D, 15);
    insertUnique(D, 25);
    insertUnique(D, 35);
    insertUnique(D, 45);
    insertUnique(D, 55);
    insertUnique(D, 65);
    insertUnique(D, 95);
    insertUnique(D, 5);
    insertUnique(D, 85);
    insertUnique(D, 105);

    printf("\n--- Initial Table ---\n");
    displayDict(D);

    // Search examples
    printf("\nIs 35 in the table? %s\n", isMember(D, 35) ? "Yes" : "No");
    printf("Is 99 in the table? %s\n", isMember(D, 99) ? "Yes" : "No");

    // Delete some
    deleteMem(D, 25);
    deleteMem(D, 75);
    deleteMem(D, 99);

    insertUnique(D, 102);

    printf("\n--- After Deletion ---\n");
    displayDict(D);

    return 0;
}
