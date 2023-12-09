#include <stdio.h>
#include <stdlib.h>

void displayMemory(int f[], int size) {
    printf("Memory Blocks:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");
}

void allocateBlocks(int f[], int st, int len) {
    for (int j = st; j < st + len; j++) {
        if (f[j] == 0) {
            f[j] = 1;
            printf("%d-------->%d\n", j, f[j]);
        } else {
            printf("%d Block is already allocated\n", j);
            len++;
        }
    }
}

int main() {
    int f[50];
    int p, st, len, c, a;

    // Initialize memory blocks
    for (int i = 0; i < 50; i++) {
        f[i] = 0;
    }

    // Input: Number of blocks already allocated
    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    // Input: Blocks already allocated
    printf("Enter blocks already allocated: ");
    for (int i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    // Memory allocation loop
    do {
        // Input: Index starting block and length
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);

        // Check if starting block is available
        if (f[st] == 0) {
            // Allocate blocks
            allocateBlocks(f, st, len);
        } else {
            printf("%d starting block is already allocated\n", st);
        }

        // Display current state of memory
        displayMemory(f, 50);

        // Input: Continue allocating (Yes - 1/No - 0)
        printf("Do you want to enter more files? (Yes - 1/No - 0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}

