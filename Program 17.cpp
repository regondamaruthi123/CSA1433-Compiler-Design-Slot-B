%{
#include <stdio.h>
%}

%%
#define[ \t]+([A-Za-z_][A-Za-z0-9_]*)[ \t]+([0-9]*\.?[0-9]+)[ \t]*\n {
    printf("Constant: %s = %s\n", yytext, $2);
}

[0-9]+ {
    printf("Constant: %s\n", yytext);
}

.|\n { /* Ignore other characters */ }

%% 

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            yyin = file;
            yylex();
            fclose(file);
        } else {
            printf("Error opening file.\n");
        }
    } else {
        printf("Usage: %s <source_file.c>\n", argv[0]);
    }
    return 0;
}
