#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int binarySearch(char names[][MAX_LENGTH], int size, const char *target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the middle element with the target
        int cmp = strcmp(names[mid], target);
        if (cmp == 0) {
            return mid; // Found the name
        }
        if (cmp < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Not found
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    // Input the number of names
    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character after the number

    // Input the names
    printf("Enter %d names (sorted alphabetically):\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // Remove newline
    }

    // Input the name to search for
    char target[MAX_LENGTH];
    printf("Enter the name to search for: ");
    fgets(target, MAX_LENGTH, stdin);
    target[strcspn(target, "\n")] = '\0'; // Remove newline

    // Perform binary search
    int result = binarySearch(names, n, target);

    if (result != -1) {
        printf("Name found at index: %d\n", result);
    } else {
        printf("Name not found in the list.\n");
    }

    return 0;
}
