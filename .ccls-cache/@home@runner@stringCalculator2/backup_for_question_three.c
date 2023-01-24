/*
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isdigit()

int Add(char *numbers) {
    int sum = 0;
    char *token;
    char delim[] = "$();',.[]{} \\n";
    char selected_delim[] = ""; //where the users selected delim is stored
    int input_strlen = strlen(numbers)-2;//gets the length of the string without '/0'
  
    //checking to see if the last input is a number or not!
    if(isdigit(numbers[input_strlen])) {
      
    
    // split numbers by user selected delimiter character; 
    token = strtok(numbers, delim);

    // add all the numbers together
    while (token != NULL) {
        sum += atoi(token);
        token = strtok(NULL, "$();',.[]{} \\n");
    }
  //}
} 
    else {
      printf("ERROR! Last input is not a number!\n");
  }//end of isdigit if statement
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






/*

#include <stdio.h>
#include <string.h>
#include <ctype.h> // isdigit()
#include <stdlib.h> // atoi()

int Add(char *numbers) {
    int sum = 0;
    char *token;
    char delim[] = "$();',.[]{} \\n";
    char selected_delim[] = ""; //where the users selected delim is stored
    int input_strlen = strlen(numbers)-2;//gets the length of the string without '/0'
    char negative_numbers[1000] = ""; //string to store negative numbers
    int negative_count = 0; //count of negative numbers
    int number;

    //checking if the input has a custom delimiter
    if (numbers[0] == '/' && numbers[1] == '/') {
        //extracting the custom delimiter
        int i = 2;
        while (numbers[i] != '\n') {
            selected_delim[i-2] = numbers[i];
            i++;
        }
        selected_delim[i-2] = '\0';
        numbers = numbers + i + 1; //moving the pointer to the next line after the custom delimiter
    }
    else {
        strcpy(selected_delim, delim);
    }

    //checking to see if the last input is a number or not!
    if(isdigit(numbers[input_strlen])) {

    // split numbers by user selected delimiter character; 
    token = strtok(numbers, selected_delim);

    // add all the numbers together
    while (token != NULL) {
        number = atoi(token);
        if (number < 0) {
            negative_count++;
            sprintf(negative_numbers, "%s%d,", negative_numbers, number);
        }
        else if (number <= 1000) {
            sum += number;
        }
        token = strtok(NULL, selected_delim);
    }

    if (negative_count > 0) {
        negative_numbers[strlen(negative_numbers)-1] = '\0'; //removing the last comma
        printf("negatives not allowed: %s\n", negative_numbers);
    }
    else {
        printf("Sum: %d\n", sum);
    }
} 
    else {
      printf("ERROR! Last input is not a number!\n");
  }//end of isdigit if


*/
