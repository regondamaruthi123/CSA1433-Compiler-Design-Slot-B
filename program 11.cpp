#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char lookahead;

void nextChar() {
    lookahead = getchar();
}

void error() {
    printf("Error: Invalid expression\n");
    exit(1);
}

void match(char expected) {
    if (lookahead == expected) {
        nextChar();
    } else {
        error();
    }
}

// Forward declarations for precedence parsing
int expression();
int term();
int factor();
int power();

// Parsing functions
int expression() {
    int result = term();
    while (lookahead == '+' || lookahead == '-') {
        char op = lookahead;
        match(lookahead);
        int value = term();
        result = (op == '+') ? result + value : result - value;
    }
    return result;
}

int term() {
    int result = power();
    while (lookahead == '*' || lookahead == '/') {
        char op = lookahead;
        match(lookahead);
        int value = power();
        result = (op == '*') ? result * value : result / value;
    }
    return result;
}

int power() {
    int result = factor();
    while (lookahead == '^') {
        match('^');
        int value = factor();
        result = (int)pow(result, value); // Exponentiation
    }
    return result;
}

int factor() {
    if (isdigit(lookahead)) {
        int value = 0;
        while (isdigit(lookahead)) {
            value = value * 10 + (lookahead - '0');
            nextChar();
        }
        return value;
    } else if (lookahead == '(') {
        match('(');
        int result = expression();
        match(')');
        return result;
    } else {
        error();
    }
    return 0; // To satisfy the compiler
}

int main() {
    printf("Enter a mathematical expression: ");
    nextChar();
    int result = expression();
    if (lookahead == '\n') {
        printf("Result: %d\n", result);
    } else {
        error();
    }
    return 0;
}