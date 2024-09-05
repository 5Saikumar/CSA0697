#include <stdio.h>
int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++; 
        str++; 
    }
    return length;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    size_t len = stringLength(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    int length = stringLength(str);
    printf("The length of the string is: %d\n", length);
    return 0;
}

