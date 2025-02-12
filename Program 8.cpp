#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct Symbol {
    char name[50];
    char type[20]; 
    int scope;     
    struct Symbol* next; 
} Symbol;
Symbol* symbolTable[TABLE_SIZE];
unsigned int hash(const char* name) {
    unsigned int hashValue = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + name[i]) % TABLE_SIZE;
    }
    return hashValue;
}
Symbol* createSymbol(const char* name, const char* type, int scope) {
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->scope = scope;
    newSymbol->next = NULL;
    return newSymbol;
}
void insertSymbol(const char* name, const char* type, int scope) {
    unsigned int index = hash(name);
    Symbol* newSymbol = createSymbol(name, type, scope);
    newSymbol->next = symbolTable[index];
    symbolTable[index] = newSymbol;
    printf("Symbol '%s' inserted successfully.\n", name);
}
Symbol* searchSymbol(const char* name) {
    unsigned int index = hash(name);
    Symbol* current = symbolTable[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void deleteSymbol(const char* name) {
    unsigned int index = hash(name);
    Symbol* current = symbolTable[index];
    Symbol* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                symbolTable[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Symbol '%s' deleted successfully.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Symbol '%s' not found.\n", name);
}
void displaySymbolTable() {
    printf("\nSymbol Table:\n");
    printf("--------------------------------------------------\n");
    printf("Index\tName\t\tType\t\tScope\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol* current = symbolTable[i];
        while (current != NULL) {
            printf("%d\t%s\t\t%s\t\t%d\n", i, current->name, current->type, current->scope);
            current = current->next;
        }
    }
    printf("--------------------------------------------------\n");
}
int main() {
    int choice;
    char name[50], type[20];
    int scope;
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbolTable[i] = NULL;
    }
    while (1) {
        printf("\nSymbol Table Operations:\n");
        printf("1. Insert Symbol\n");
        printf("2. Search Symbol\n");
        printf("3. Delete Symbol\n");
        printf("4. Display Symbol Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter type: ");
                scanf("%s", type);
                printf("Enter scope: ");
                scanf("%d", &scope);
                insertSymbol(name, type, scope);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Symbol* found = searchSymbol(name);
                if (found) {
                    printf("Symbol found: Name = %s, Type = %s, Scope = %d\n", found->name, found->type, found->scope);
                } else {
                    printf("Symbol '%s' not found.\n", name);
                }
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteSymbol(name);
                break;
            case 4:
                displaySymbolTable();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
