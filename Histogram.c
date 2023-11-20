#include <stdio.h>

#define MAX_LENGTH 20 // Maximum word length

void printHistogram(int lengths[]) {
    int maxCount = 0;
    
    // Find the maximum count
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (lengths[i] > maxCount) {
            maxCount = lengths[i];
        }
    }

    // Print the histogram
    for (int row = maxCount; row > 0; row--) {
        for (int col = 0; col < MAX_LENGTH; col++) {
            if (lengths[col] >= row) {
                printf("  *");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print the x-axis labels
    for (int col = 0; col < MAX_LENGTH; col++) {
        printf("---");
    }
    printf("\n");
    for (int col = 0; col < MAX_LENGTH; col++) {
        printf("%2d ", col + 1);
    }
    printf("\n");
}

int main() {
    int lengths[MAX_LENGTH] = {0}; // Array to store the count of each word length

    printf("Enter input: ");

    // Read input words and count their lengths
    char word[MAX_LENGTH];
    while (scanf("%s", word) != EOF) {
        int length = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            length++;
        }
        if (length <= MAX_LENGTH) {
            lengths[length - 1]++;
        }
    }

    // Print the histogram
    printf("\nHistogram:\n");
    printHistogram(lengths);

    return 0;
}