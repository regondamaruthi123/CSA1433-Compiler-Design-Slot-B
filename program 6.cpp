#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char* left, char right1[], char right2[]) {
    if (right1[0] == left[0]) {
        printf("%s → %s' \n", left, right2);
        printf("%s' → %s%s' | ε\n", left, right1+1, left);
    } else {
        printf("%s → %s | %s\n", left, right1, right2); 
    }
}
  
int main() {
    char left[] = "A";
    char right1[] = "Aα";
    char right2[] = "β";

    eliminateLeftRecursion(left, right1, right2);
    
    return 0;
}
  