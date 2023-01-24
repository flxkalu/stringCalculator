
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delimiter_of_any_length(char *input, char *delimiter) {
    if(input[0] == '/' && input[1] == '/' && input[2] == '[') {
        int i = 3, j = 0;
        while (input[i] != ']') {
            delimiter[j++] = input[i++];
        }
        delimiter[j] = '\0';
        return 1;
    }
    return 0;
}

int add(char *delimiter, char *input) {
    char *token = strtok(input, delimiter);
    int sum = 0;
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, delimiter);
    }
    return sum;
}

int main() {
    char input[100];
    char delimiter[10];

    printf("Enter delimiter: ");
    fgets(input, 100, stdin);
    if (!delimiter_of_any_length(input, delimiter)) {
        printf("Invalid delimiter\n");
        return 0;
    }

    printf("Enter input string: ");
    fgets(input, 100, stdin);
    int sum = add(delimiter, input);
    printf("Sum: %d\n", sum);
    return 0;
}
*/