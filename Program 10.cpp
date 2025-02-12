#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lookahead;

void nextChar() { lookahead = getchar(); }
void error() { printf("Error\n"); exit(1); }
void match(char expected) { if (lookahead == expected) nextChar(); else error(); }

void expression() {
    term();
    while (lookahead == '+' || lookahead == '-') match(lookahead), term();
}

void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') match(lookahead), factor();
}

void factor() {
    if (isdigit(lookahead)) match(lookahead);
    else if (lookahead == '(') match('('), expression(), match(')');
    else error();
}

int main() {
    nextChar();
    expression();
    printf(lookahead == '\n' ? "Valid expression\n" : "Error\n");
    return 0;
}
