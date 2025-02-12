#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register",
    "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic",
    "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"
};

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;  // It is a keyword
        }
    }
    return 0;
}

// Function to check if an identifier is valid
int isValidIdentifier(const char *str) {
    // Check if the first character is a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;  // Invalid identifier
    }

    // Check the rest of the characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;  // Invalid identifier
        }
    }

    // Check if it's a keyword
    if (isKeyword(str)) {
        return 0;  // Invalid because it's a keyword
    }

    return 1;  // Valid identifier
}

int main() {
    char identifier[50];

    // Get user input
    printf("Enter an identifier: ");
    scanf("%49s", identifier); // Read input (limit to avoid buffer overflow)

    // Check if valid identifier
    if (isValidIdentifier(identifier)) {
        printf("Valid Identifier\n");
    } else {
        printf("Invalid Identifier\n");
    }

    return 0;
}
