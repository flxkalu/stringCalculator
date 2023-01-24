/*
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isdigit()

int Add(char *numbers) {
    int sum = 0;
    char *token;
    int input_strlen = strlen(numbers)-2;//gets the length of the string without '/0'
  
    //checking to see if the last input is a number or not!
    if(isdigit(numbers[input_strlen])) {
    // split numbers by ',' or '\n'
      
    token = strtok(numbers, "();',.[]{} \\n");
      printf("from token side %s" , token);

    // add all the numbers together
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, ",\\n");
    }
  } else {
      printf("ERROR! Last input is not a number!\n");
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