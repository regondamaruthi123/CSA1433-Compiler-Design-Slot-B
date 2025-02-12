#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isValidGrammar(const char *input) {
    int length = strlen(input);
    if (length == 0) return 0; 
    if (!isupper(input[0])) return 0; 
    if (input[length - 1] != '.') return 0; 
    return 1; 
}
int main() {
    const char *testString = "Hello, this is a test.";
    if (isValidGrammar(testString)) {
        printf("The string satisfies the grammar rules.\n");
    } else {
        printf("The string does not satisfy the grammar rules.\n");
    }
    return 0;
}
