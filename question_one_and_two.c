/*
#include <stdio.h>
#include <string.h>

int Add(char *numbers) {
    int sum = 0;
    char *token;

    // split numbers by ',' or '\n'
    token = strtok(numbers, ",\n");

    // add all the numbers together
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, ",\n");
    }

    return sum;
}

int main() {
    char numbers[100];
    printf("Enter numbers separated by commas or new lines: ");
    fgets(numbers, sizeof(numbers), stdin);

    int sum = Add(numbers);
    printf("Sum: %d\n", sum);

    return 0;
}
*/