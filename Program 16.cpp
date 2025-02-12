%{
#include <stdio.h>
#include <stdlib.h>

int char_count = 0; // To count characters
int line_count = 0; // To count lines
int word_count = 0; // To count words
%}

%%
[ \t]+            ; // Ignore spaces and tabs
\n               { line_count++; } // Increment line count on new line
"//".*           ; // Ignore single-line comments
"/*".* "*/"      ; // Ignore multi-line comments
[a-zA-Z_][a-zA-Z0-9_]* { word_count++; } // Count valid identifiers as words
.                { char_count++; } // Count all other characters
%% 

int main(int argc, char **argv) {
    FILE *fp;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("File opening failed");
            return EXIT_FAILURE;
        }
        yyin = fp; // Set input file
    }
    yylex(); // Start lexical analysis
    printf("Characters: %d\nLines: %d\nWords: %d\n", char_count, line_count, word_count);
    fclose(fp); // Close the file
    return 0;
}
