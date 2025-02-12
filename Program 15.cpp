#include <stdio.h>

void generateCode(const char* operation, int operand1, int operand2) {
    printf("MOV R1, %d\n", operand1);
    printf("MOV R2, %d\n", operand2);
    
    if (operation == "+") {
        printf("ADD R1, R2\n");
    } else if (operation == "-") {
        printf("SUB R1, R2\n");
    } else if (operation == "*") {
        printf("MUL R1, R2\n");
    } else if (operation == "/") {
        printf("DIV R1, R2\n");
    }
    
    printf("STORE R1, RESULT\n");
}

int main() {
    generateCode("+", 5, 3);
    return 0;
}
