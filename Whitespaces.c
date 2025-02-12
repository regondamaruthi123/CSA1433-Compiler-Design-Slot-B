#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int whitespaceCount = 0, newlineCount = 0;

    // Open the file for reading
    file = fopen("input.txt", "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read character by character
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\t') {
            whitespaceCount++;
        } else if (ch == '\n') {
            newlineCount++;
        }
    }

    // Close the file
    fclose(file);

    // Display the counts
    printf("Number of whitespace characters: %d\n", whitespaceCount);
    printf("Number of newline characters: %d\n", newlineCount);

    return 0;
}
